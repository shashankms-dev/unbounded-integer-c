#include "ubint.h"

ubint *ub_zero(void) {
    ubint *zero = malloc(sizeof(ubint));
    zero->sign = 0;
    zero->length = 1;
    zero->blocks = malloc(sizeof( uint32_t ));
    zero->blocks[0] = 0;

    return zero;
}
