#include <stdint.h>
#include "ubint.h"

ubint *ub_add(ubint *num1, ubint *num2) {
    ubint *res;
    int cmp;
    
    if(num1->sign != num2->sign) {
        res = ub_abssubtract(num1, num2);
        cmp = ub_abscompare(num1, num2);
        
        if(cmp == 1) {
            res->sign = num1->sign;
        }
        else if(cmp == -1) {
            res->sign = num2->sign;
        }
        else {
            return res;
        }
    }
    else {
        res = ub_absadd(num1, num2);
        res->sign = num1->sign;
    }

    return res;
}
