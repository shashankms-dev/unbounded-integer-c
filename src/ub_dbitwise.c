#include <stdint.h>
#include "ubint.h"

void ub_dand(ubint *num, ubint *mask) {
    uint64_t iter1 = num->length;
    uint64_t iter2 = mask->length;

    while(iter1 > 0 && iter2 > 0) {
        num->blocks[--iter1] &= mask->blocks[--iter2];
    }
}

void ub_dor(ubint *num, ubint *mask) {
    uint64_t iter1 = num->length;
    uint64_t iter2 = mask->length;

    while(iter1 > 0 && iter2 > 0) {
        num->blocks[--iter1] |= mask->blocks[--iter2];
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

void ub_dxor(ubint *num, ubint *mask) {
    uint64_t iter1 = num->length;
    uint64_t iter2 = mask->length;

    while(iter1 > 0 && iter2 > 0) {
        num->blocks[--iter1] ^= mask->blocks[--iter2];
    }
}

void ub_dxnor(ubint *num, ubint *mask) {
    ub_dxor(num, mask);
    ub_dnot(num);
}
