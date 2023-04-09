#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include "ubint.h"

ubint *ub_create(uint8_t sign, uint64_t length, ...) {
    ubint *num;
    num = malloc(sizeof(ubint));
    num->sign = sign;
    num->length = length;
    num->blocks = malloc(sizeof( uint32_t[num->length] ));

    va_list blocks;
    va_start(blocks, length);
    
    for(uint64_t i = 0; i < length; i++) {
    	num->blocks[i] = va_arg(blocks, uint32_t);
    }
    
    return num;
}

void ub_free(ubint *num) {
    free(num->blocks);
    free(num);
}

ubint *ub_clone(ubint *num) {
    ubint *clone = malloc(sizeof(ubint));
    clone->sign = num->sign;
    clone->length = num->length;
    clone->blocks = malloc(sizeof( uint32_t[clone->length] ));
    for(uint64_t i = 0; i < num->length; i++) {
        clone->blocks[i] = num->blocks[i];
    }

    return clone;
}

void ub_print(ubint *num) {
    uint64_t i;

    if(num->sign)
        printf("-");

    for(i = 0; i < num->length; i++) {
        if(num->blocks[i] != 0)
            break;
    }

    for(; i < num->length; i++) {
        printf("%08x", num->blocks[i]);
    }
}
