#include <stdio.h>
#include "ubint.h"

void ub_print(ubint *num) {
    if(num->sign)
        printf("-");

    for(uint64_t i = 0; i < num->length; i++) {
        printf("%08x", num->blocks[i]);
    }
}

