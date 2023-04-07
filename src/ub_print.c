#include <stdio.h>
#include <stdint.h>
#include "ubint.h"

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

