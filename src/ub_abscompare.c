#include "ubint.h"

int ub_abscompare(ubint *num1, ubint *num2) {
    if(num1->length != num2->length) {
        return (num1->length > num2->length) ? 1 : -1;
    }

    if(num1->blocks[0] > num2->blocks[0]) {
        return 1;
    }
    else if(num1->blocks[0] < num2->blocks[0]) {
        return -1;
    }
    else {
        return 0;
    }
}
