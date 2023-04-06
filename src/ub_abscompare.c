#include "ubint.h"

int ub_abscompare(ubint *num1, ubint *num2) {
    if(num1->length != num2->length) {
        return (num1->length > num2->length) ? 1 : -1;
    }

    for(uint64_t i = num1->length; i > 0; i--) {
        i = i - 1;
        if(num1->blocks[i] != num2->blocks[i]) {
            return (num1->blocks[i] > num2->blocks[i]) ? 1 : -1;
        }
    }

    return 0;
}
