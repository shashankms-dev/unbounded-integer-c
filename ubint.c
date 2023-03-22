#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include "ubint.h"

ubint *ub_constructor(uint8_t sign, uint64_t nblocks, ...) {
	ubint *number;
	number->blocks = (uint64_t *)malloc(sizeof(uint64_t[nblocks]));

	va_list blocks;
	va_start(blocks, nblocks);

	for(uint64_t i = 0; i < nblocks; i++) {
		number->blocks[i] = va_arg(blocks, uint64_t);
	}
	number->sign = sign;
	number->nblocks = nblocks;

	return number;
}

void ub_destructor(ubint *number) {
	free(number->blocks);
	free(number);
}

void ub_print(ubint *number) {
	if(number->sign) {
		printf("-");
	}

	for(uint64_t i = 0; i < number->nblocks; i++) {
		if(number->blocks[i] != 0) {
			printf("%llu", number->blocks[i]);
		}
		else {
			printf("00000000000000000000");
		}
	}
}
