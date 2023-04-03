#include <stdio.h>
#include "ubint.h"

void ub_print(ubint *number) {
    if(number->sign)
        printf("-");

    for(uint64_t i = 0; i < number->n_blocks; i++) {
        printf("%08x", number->blocks[i]);
    }
}

