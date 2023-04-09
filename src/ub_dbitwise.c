#include <stdint.h>
#include "ubint.h"

void ub_dand(ubint *num1, ubint *num2) {
    uint64_t iter1 = num1->length;
    uint64_t iter2 = num2->length;

    while(iter1 > 0 && iter2 > 0) {
        num1->blocks[--iter1] &= num2->blocks[--iter2];
    }
}

void ub_dor(ubint *num1, ubint *num2) {
    uint64_t iter1 = num1->length;
    uint64_t iter2 = num2->length;

    while(iter1 > 0 && iter2 > 0) {
        num1->blocks[--iter1] |= num2->blocks[--iter2];
    }
}

void ub_dnot(ubint *num) {
    for(uint64_t i = 0; i < num->length; i++) {
        num->blocks[i] = ~(num->blocks[i]);
    }
}

void ub_dtwos_complement(ubint *num) {
    uint64_t iter;

    ub_dnot(num);

    for(uint64_t i = num->length; i > 0; i--) {
        iter = i - 1;
        num->blocks[iter] += 1;
        if(num->blocks[iter] != 0) {
            break;
        }
    }
}

void ub_dxor(ubint *num1, ubint *num2) {
    uint64_t iter1 = num1->length;
    uint64_t iter2 = num2->length;

    while(iter1 > 0 && iter2 > 0) {
        num1->blocks[--iter1] ^= num2->blocks[--iter2];
    }
}

void ub_dxnor(ubint *num1, ubint *num2) {
    ub_dxor(num1, num2);
    ub_dnot(num1);
}
