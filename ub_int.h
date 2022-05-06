#ifndef UBINT_H
#define UBINT_H

#include <stdint.h>

typedef struct unbounded_integer {
	uint64_t *blocks;
	uint64_t size;
	uint8_t sign;
} ubint_t;

// Constructor for ubint_t
ubint_t ub_constructor(uint8_t sign, uint64_t size, ...);

// Destructor for ubint_t
void ub_destructor(ubint_t *number);

// Print given ubint_teger
void ub_print(ubint_t number);

#endif
