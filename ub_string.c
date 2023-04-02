#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ubint.h"

uint64_t ub_pow(uint32_t index) {
    uint64_t res = 1;
    for(; index > 0; index--) {
        res = (res << 3) + (res << 1);
    }
    return res;
}

ubint *ub_string(char *num_string) {
    ubint *number = malloc( sizeof(ubint) );

    uint64_t n_digits = strlen(num_string);

    if(num_string[0] == '-') {
        number->sign = 1;
        num_string++;
        n_digits -= 1;
    }
    else {
        number->sign = 0;
    }

    number->n_blocks = ceill( (long double)n_digits / 9.632 );
    number->blocks = malloc( sizeof(uint32_t[number->n_blocks]) );

    uint64_t pos = n_digits;
    uint64_t tmp = 0, index = number->n_blocks - 1;
    uint32_t block;

    for(uint32_t i = 0; pos > 0; i++) {
        tmp += (num_string[--pos] - '0') * ub_pow(i);
        if(tmp >= 0xffffffff) {
            printf("block[%lu] = %08x \n", index, block);
            block = (uint32_t) tmp;
            tmp = tmp >> 32;
            number->blocks[index--] = block;
        }
        if(pos == 0) {
            printf("block[%lu] = %016lx \n", index, tmp);
            number->blocks[index] = (uint32_t) tmp;
            break;
        }
    }

    return number;
}

