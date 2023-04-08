#include <stdint.h>
#include "ubint.h"

void ub_dor(ubint *num, ubint *oper) {
    uint64_t iter1, iter2;

    iter1 = num->length;
    iter2 = oper->length;
    while(1) {
        if(iter1 == 0 || iter2 == 0) {
            break;
        }
        num->blocks[--iter1] |= oper->blocks[--iter2];
    }
}
