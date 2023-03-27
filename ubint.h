#ifndef UBINT_H
#define UBINT_H

#include <stdint.h>

typedef struct unbounded_integer {
	uint64_t *blocks;
	uint64_t nblocks;
	uint8_t sign;
} ubint;

ubint *ub_constructor(uint8_t, uint64_t, ...);

void ub_destructor(ubint *);

ubint *ub_string(char *);

void ub_print(ubint *);

#endif
