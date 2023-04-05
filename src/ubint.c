#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include "ubint.h"

ubint *ub_constructor(uint8_t sign, uint64_t n_blocks, ...) {
    ubint *number;
    number = malloc( sizeof(ubint) );
    number->blocks = malloc( sizeof(uint32_t[n_blocks]) );
    
    va_list blocks;
    va_start(blocks, n_blocks);
    
    for(uint64_t i = 0; i < n_blocks; i++) {
    	number->blocks[i] = va_arg(blocks, uint32_t);
    }
    number->sign = sign;
    number->n_blocks = n_blocks;
    
    return number;
}

void ub_destructor(ubint *number) {
    free(number->blocks);
    free(number);
}

ubint *ub_clone(ubint *num) {
    ubint *new = malloc(sizeof(ubint));
    new->sign = num->sign;
    new->n_blocks = num->n_blocks;
    new->blocks = malloc(sizeof(uint32_t[new->n_blocks]));
    for(uint64_t i = 0; i < num->n_blocks; i++) {
        new->blocks[i] = num->blocks[i];
    }

    return new;
}
