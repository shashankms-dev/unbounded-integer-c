#include "ubint.h"

int ub_compare(ubint *num1, ubint *num2) {
    if(num1->sign != num2->sign)
        return (num1->sign) ? -1 : 1;

    if(num1->sign) {
        return -1 * ub_abscompare(num1, num2);
    }
    else {
        return ub_abscompare(num1, num2);
    }
}
