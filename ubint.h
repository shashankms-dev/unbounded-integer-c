#ifndef UBINT_H
#define UBINT_H

#include <stdint.h>

typedef struct unbounded_integer {
	uint64_t *blocks;
	uint64_t size;
	uint8_t sign;
} ubint;

// Constructor for ubint
ubint ub_constructor(uint8_t sign, uint64_t size, ...);

// Destructor for ubint
void ub_destructor(ubint *number);

// Print given ubinteger
void ub_print(ubint number);

#endif
