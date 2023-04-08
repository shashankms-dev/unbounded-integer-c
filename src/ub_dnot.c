#include <stdint.h>
#include "ubint.h"

void ub_inot(ubint *num) {
    for(uint64_t i = 0; i < num->length; i++) {
        num->blocks[i] = ~(num->blocks[i]);
    }
}
