#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ubint.h"

//#define BLOCK_MAX "18446744073709551615"

ubint *ub_constructor(uint8_t sign, uint64_t n_blocks, ...) {
	ubint *number;
	number = (ubint *)malloc(sizeof(ubint));
	number->blocks = (uint64_t *)malloc(sizeof(uint64_t[n_blocks]));

	va_list blocks;
	va_start(blocks, n_blocks);

	for(uint64_t i = 0; i < n_blocks; i++) {
		number->blocks[i] = va_arg(blocks, uint64_t);
	}
	number->sign = sign;
	number->n_blocks = n_blocks;

	return number;
}

void ub_destructor(ubint *number) {
	free(number->blocks);
	free(number);
}

ubint *ub_string(char *num_string) {
	ubint *number;
	uint64_t n_blocks;

	number = (ubint *)malloc(sizeof(ubint));

	uint64_t n_digits = strlen(num_string);
	
	if(num_string[0] == '-') {
		number->sign = 1;
		num_string++;
		n_digits -= 1;
	}

	n_blocks = n_digits / 19;
	
	number->blocks = (uint64_t *)malloc(sizeof(uint64_t[n_blocks]));
	number->n_blocks = n_blocks;

	uint64_t pos = n_digits - 1;
	unsigned __int128 num = 0;
	uint64_t block;
	uint64_t index = n_blocks - 1;
	uint32_t break_flag = 0;

	while(break_flag == 0) {
		for(int i = 0; i < 20 && break_flag == 0; i++) {
			if (pos == 0) break_flag = 1;
			num += (unsigned)(num_string[pos--] - '0') * (unsigned __int128)pow(10, i);
		}
		block = (uint64_t)(num & 0xffffffffffffffff);
		num &= 0xffffffffffffffff0000000000000000;
		num = num >> 64;
		number->blocks[index--] = block;
	}

	return number;
}

void ub_print(ubint *number) {
	if(number->sign)
		printf("-");

	for(uint64_t i = 0; i < number->n_blocks; i++) {
		//if(number->blocks[i] != 0) {
			printf("%lu", number->blocks[i]);
		//}
		//else {
		//	printf("00000000000000000000");
		//}
	}
}
