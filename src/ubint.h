#ifndef UBINT_H
#define UBINT_H

#include <stdint.h>

typedef struct unbounded_integer {
	uint32_t *blocks;
	uint64_t length;
	uint8_t sign;
} ubint;

ubint *ub_constructor(uint8_t, uint64_t, ...);

void ub_destructor(ubint *);

ubint *ub_string(char *);

ubint *ub_hex_string(char *);

void ub_print(ubint *);

int ub_compare(ubint *, ubint *);

int ub_abscompare(ubint *, ubint *);

ubint *ub_add(ubint *, ubint *);

ubint *ub_subtract(ubint *, ubint *);

ubint *ub_multiply(ubint *, ubint *);

ubint *ub_divide(ubint *, ubint *);

#endif
