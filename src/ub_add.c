#include <stdint.h>
#include <stdlib.h>
#include "ubint.h"

// Assuming both positive or both negative operands for now, not handling signage only magnitude

ubint *ub_add(ubint *num1, ubint *num2) {
    ubint *res = malloc(sizeof(ubint));
    uint64_t buffer;
    uint64_t iter, iter1, iter2;
    uint32_t carry = 0, val1, val2;

    res->n_blocks = (num1->n_blocks > num2->n_blocks) ? (num1->n_blocks + 1) : (num2->n_blocks + 1);
    res->blocks = malloc(sizeof(uint32_t[res->n_blocks]));
    if(num1->sign == 0 && num2->sign == 0) {
        res->sign = 0;
    }
    else {
        res->sign = 1;
    }

    iter = res->n_blocks;
    iter1 = num1->n_blocks;
    iter2 = num2->n_blocks;

    while(1) {
        val1 = (iter1 > 0) ? num1->blocks[--iter1] : 0;
        val2 = (iter2 > 0) ? num2->blocks[--iter2] : 0;
        buffer = val1 + val2 + carry;
        res->blocks[--iter] = (uint32_t) buffer;
        carry = buffer >> 32;

        if(iter1 == 0 && iter2 == 0) {
            res->blocks[--iter] = (uint32_t) carry;
            break;
        }
    }

    return res;
}
