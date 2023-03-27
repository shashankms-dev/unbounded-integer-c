#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "ubint.h"

#define BLOCK_MAX "18446744073709551615"

ubint *ub_constructor(uint8_t sign, uint64_t nblocks, ...) {
	ubint *number;
	number = (ubint *)malloc(sizeof(ubint));
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

ubint *ub_string(char *num_string) {
	ubint *number;
	uint64_t nblocks;

	number = (ubint *)malloc(sizeof(ubint));

	uint64_t length = strlen(num_string);
	
	if(num_string[0] == '-') {
		number->sign = 1;
		length -= 1;
	}

	nblocks = (length / 20);
	if ((length % 20) != 0) {
		nblocks += 1;
	}
	
	number->blocks = (uint64_t *)malloc(sizeof(uint64_t[nblocks]));
	number->nblocks = nblocks;

	for(uint64_t i = 0; i < nblocks; i++) {
		char tmp[21];
		strncpy(tmp, num_string[20*i], 20);
		number->blocks[i] = atoll(tmp);
	}

	return number;
}

void ub_print(ubint *number) {
	if(number->sign)
		printf("-");

	for(uint64_t i = 0; i < number->nblocks; i++) {
		if(number->blocks[i] != 0) {
			printf("%llu", number->blocks[i]);
		}
		else {
			printf("00000000000000000000");
		}
	}
}
