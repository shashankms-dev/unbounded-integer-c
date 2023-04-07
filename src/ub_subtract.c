#include <stdint.h>
#include "ubint.h"

ubint *ub_subtract(ubint *num1, ubint *num2) {
    ubint *res;
    int cmp;

    if(num1->sign != num2->sign) {
        res = ub_absadd(num1, num2);
        res->sign = (num1->sign) ? 1 : 0;
    }
    else {
        cmp = ub_abscompare(num1, num2);
        res = ub_abssubtract(num1, num2);
        if(num1->sign) {
            res->sign = (cmp == 1) ? 1 : 0;
        }
        else {
            res->sign = (cmp == -1) ? 1 : 0;
        }
    }
    
    return res;
}
