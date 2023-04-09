#include "ubint.h"

int ub_compare(ubint *num1, ubint *num2) {
    if(num1->sign != num2->sign)
        return (num1->sign) ? -1 : 1;

    if(num1->sign) {
        return -1 * ub_abs_compare(num1, num2);
    }
    else {
        return ub_abs_compare(num1, num2);
    }
}

int ub_abs_compare(ubint *num1, ubint *num2) {
    uint64_t iter;

    if(num1->length != num2->length) {
        return (num1->length > num2->length) ? 1 : -1;
    }

    for(uint64_t i = num1->length; i > 0; i--) {
        iter = i - 1;
        if(num1->blocks[iter] != num2->blocks[iter]) {
            return (num1->blocks[iter] > num2->blocks[iter]) ? 1 : -1;
        }
    }

    return 0;
}
