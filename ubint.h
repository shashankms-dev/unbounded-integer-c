#ifndef UBINT_H
#define UBINT_H

#include <stdint.h>

typedef struct unbounded_integer {
	uint64_t *blocks;
	uint64_t nblocks;
	uint8_t sign;
} ubint;

ubint *ub_constructor(uint8_t sign, uint64_t nblocks, ...);

void ub_destructor(ubint *number);

void ub_print(ubint *number);

#endif
