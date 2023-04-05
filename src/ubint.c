#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include "ubint.h"

ubint *ub_constructor(uint8_t sign, uint64_t length, ...) {
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

void ub_destructor(ubint *num) {
    free(num->blocks);
    free(num);
}

ubint *ub_clone(ubint *num) {
    ubint *copy = malloc(sizeof(ubint));
    copy->sign = num->sign;
    copy->length = num->length;
    copy->blocks = malloc(sizeof( uint32_t[copy->length] ));
    for(uint64_t i = 0; i < num->length; i++) {
        copy->blocks[i] = num->blocks[i];
    }

    return copy;
}
