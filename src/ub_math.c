#include <stdlib.h>
#include <stdint.h>
#include "ubint.h"

ubint *ub_add(ubint *num1, ubint *num2) {
    ubint *res;
    int cmp;
    
    if(num1->sign != num2->sign) {
        res = ub_abs_subtract(num1, num2);
        cmp = ub_abs_compare(num1, num2);
        
        if(num1->sign) {
            res->sign = (cmp == 1) ? 1 : 0;
        }
        else {
            res->sign = (cmp == -1) ? 1 : 0;
        }
    }
    else {
        res = ub_abs_add(num1, num2);
        res->sign = num1->sign;
    }

    return res;
}

ubint *ub_subtract(ubint *num1, ubint *num2) {
    ubint *res;
    int cmp;

    if(num1->sign != num2->sign) {
        res = ub_abs_add(num1, num2);
        res->sign = (num1->sign) ? 1 : 0;
    }
    else {
        cmp = ub_abs_compare(num1, num2);
        res = ub_abs_subtract(num1, num2);
        if(num1->sign) {
            res->sign = (cmp == 1) ? 1 : 0;
        }
        else {
            res->sign = (cmp == -1) ? 1 : 0;
        }
    }

    return res;
}

ubint *ub_abs_add(ubint *num1, ubint *num2) {
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

ubint *ub_abs_subtract(ubint *num1, ubint *num2) {
    ubint *res, *num2_twoc;
    int cmp = ub_abs_compare(num1, num2);

    if(cmp == 0) {
        return ub_zero();
    }

    if(cmp == -1) {
        ubint *tmp = num1;
        num1 = num2;
        num2 = tmp;
    }

    num2_twoc = ub_twos_complement(num2);
    res = ub_abs_add(num1, num2_twoc);
    // experimental
    res->blocks[0] = 0;

    ub_free(num2_twoc);

    return res;
}

// INCOMPLETE
ubint *ub_multiply(ubint *num1, ubint *num2) {
    ubint *res = NULL;
    return res;
}

ubint *ub_divide(ubint *num1, ubint *num2) {
    ubint *res = NULL;
    return res;
}
