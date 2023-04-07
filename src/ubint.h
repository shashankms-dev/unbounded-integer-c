#ifndef UBINT_H
#define UBINT_H

#include <stdint.h>

typedef struct unbounded_integer {
	uint32_t *blocks;
	uint64_t length;
	uint8_t sign;
} ubint;

ubint *ub_create(uint8_t, uint64_t, ...);

void ub_free(ubint *);


void ub_print(ubint *);


ubint *ub_string(char *);

ubint *ub_hex_string(char *);


ubint *ub_add(ubint *, ubint *);

ubint *ub_absadd(ubint *, ubint *);

ubint *ub_subtract(ubint *, ubint *);

ubint *ub_abssubtract(ubint *, ubint *);

ubint *ub_multiply(ubint *, ubint *);

ubint *ub_divide(ubint *, ubint *);


int ub_compare(ubint *, ubint *);

int ub_abscompare(ubint *, ubint *);


ubint *ub_zero(void);

#endif
