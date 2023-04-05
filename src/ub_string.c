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
    ubint *num = malloc(sizeof(ubint));

    uint64_t n_digits = strlen(num_string);

    if(num_string[0] == '-') {
        num->sign = 1;
        num_string++;
        n_digits -= 1;
    }
    else {
        num->sign = 0;
    }

    num->length = ceill((long double) n_digits / 9.632);
    num->blocks = malloc(sizeof( uint32_t[num->length] ));

    uint64_t pos = n_digits;
    uint64_t tmp = 0, index = num->length - 1;
    uint32_t block;

    for(uint32_t i = 0; pos > 0; i++) {
        tmp += (num_string[--pos] - '0') * ub_pow(i);
        if(tmp >= 0xffffffff) {
            printf("block[%lu] = %08x \n", index, block);
            block = (uint32_t) tmp;
            tmp = tmp >> 32;
            num->blocks[index--] = block;
        }
        if(pos == 0) {
            printf("block[%lu] = %016lx \n", index, tmp);
            num->blocks[index] = (uint32_t) tmp;
            break;
        }
    }

    return num;
}

