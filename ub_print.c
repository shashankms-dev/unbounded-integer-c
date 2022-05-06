#include "ub_int.h"
#include <stdio.h>

void ub_print(ubint_t number) {
        int start = 0;
        for(uint64_t i = 0; i < number.size; i++) {
                if(number.blocks[i] != 0 || i == number.size - 1) {
                        printf("%lu", number.blocks[i]);
                        start = 1;
                }
                else if(start != 0) {
                        printf("0000000000000000");
                }
        }
        printf("\n");
}

