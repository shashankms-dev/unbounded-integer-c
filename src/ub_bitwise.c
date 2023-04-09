#include <stdlib.h>
#include <stdint.h>
#include "ubint.h"

ubint *ub_and(ubint *num1, ubint *num2) {
    ubint *res = ub_clone(num1);
    ub_dand(res, num2);

    return res;
}

ubint *ub_or(ubint *num1, ubint *num2) {
    ubint *res = ub_clone(num1);
    ub_dor(res, num2);

    return res;
}

ubint *ub_not(ubint *num) {
    ubint *res = ub_clone(num);
    ub_dnot(res);

    return res;
}

ubint *ub_twos_complement(ubint *num) {
    ubint *res = ub_clone(num);
    ub_dtwos_complement(res);

    return res;
}

ubint *ub_xor(ubint *num1, ubint *num2) {
    ubint *res = ub_clone(num1);
    ub_dxor(res, num2);

    return res;
}

ubint *ub_xnor(ubint *num1, ubint *num2) {
    ubint *res = ub_clone(num1);
    ub_dxnor(res, num2);

    return res;
}
