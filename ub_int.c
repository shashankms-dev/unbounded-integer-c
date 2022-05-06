#include "ub_int.h"
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

ubint_t ubint_constructor(uint8_t sign, uint64_t size, ...) {
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

void ubint_destructor(ubint_t *number) {
	free(number->blocks);
}

void ubint_print(ubint_t number) {
	int start = 0;
	for(uint64_t i = 0; i < number.size; i++) {
		if(number.blocks[i] != 0 || i == number.size - 1) {
			printf("%lu", number.blocks[i]);
			start = 1;
		}
		else if(start != 0) {
			printf("0000000000000000");
		}
	}
	printf("\n");
}
