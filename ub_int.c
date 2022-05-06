#include "ub_int.h"
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>

ubint_t ub_constructor(uint8_t sign, uint64_t size, ...) {
	ubint_t number;
	number.blocks = (uint64_t *)malloc(sizeof(uint64_t[size]));

	va_list blocks;
	va_start(blocks, size);

	for(uint64_t i = 0; i < size; i++) {
		number.blocks[i] = va_arg(blocks, uint64_t);
	}
	number.sign = sign;
	number.size = size;

	return number;
}

void ub_destructor(ubint_t *number) {
	free(number->blocks);
}
