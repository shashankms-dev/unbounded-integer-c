#include <stdlib.h>
#include <stdint.h>
#include "ubint.h"

ubint *ub_absadd(ubint *num1, ubint *num2) {
    ubint *res = malloc(sizeof(ubint));
    uint64_t buffer;
    uint64_t iter, iter1, iter2;
    uint32_t carry = 0, block1, block2;

    res->sign = 0;
    res->length = (num1->length > num2->length) ? (num1->length + 1) : (num2->length + 1);
    res->blocks = malloc(sizeof( uint32_t[res->length] ));

    iter1 = num1->length;
    iter2 = num2->length;
    iter = res->length;

    while(1) {
        block1 = (iter1 > 0) ? num1->blocks[--iter1] : 0;
        block2 = (iter2 > 0) ? num2->blocks[--iter2] : 0;

        buffer = (uint64_t) block1 + block2 + carry;
        res->blocks[--iter] = (uint32_t) buffer;
        carry = buffer >> 32;

        if(iter1 == 0 && iter2 == 0) {
            res->blocks[--iter] = (uint32_t) carry;
            break;
        }
    }

    return res;
}
