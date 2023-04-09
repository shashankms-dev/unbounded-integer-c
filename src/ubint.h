#ifndef UBINT_H
#define UBINT_H

#include <stdint.h>

typedef struct unbounded_integer {
	uint32_t *blocks;
	uint64_t length;
	uint8_t sign;
} ubint;


// Basic functions
ubint *ub_create(uint8_t, uint64_t, ...);
void ub_free(ubint *);
ubint *ub_clone(ubint *);
void ub_print(ubint *);


// Functions to create number from string
ubint *ub_string(char *);
ubint *ub_hex_string(char *);


// Functions to perform arithmetic operations
ubint *ub_add(ubint *, ubint *);
ubint *ub_abs_add(ubint *, ubint *);
ubint *ub_subtract(ubint *, ubint *);
ubint *ub_abs_subtract(ubint *, ubint *);
ubint *ub_multiply(ubint *, ubint *);
ubint *ub_divide(ubint *, ubint *);


// Functions to perform comparision
int ub_compare(ubint *, ubint *);
int ub_abs_compare(ubint *, ubint *);


// Functions to perform bitwise operations
ubint *ub_and(ubint *, ubint *);
ubint *ub_or(ubint *, ubint *);
ubint *ub_not(ubint *);
ubint *ub_xor(ubint *, ubint *);
ubint *ub_xnor(ubint *, ubint *);
ubint *ub_twos_complement(ubint *);


// Functions to perform bitwise operations in place
void ub_dand(ubint *, ubint *);
void ub_dor(ubint *, ubint *);
void ub_dnot(ubint *);
void ub_dxor(ubint *, ubint *);
void ub_dxnor(ubint *, ubint *);
void ub_dtwos_complement(ubint *);

#endif
