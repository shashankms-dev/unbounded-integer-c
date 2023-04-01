#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ubint.h"

ubint *ub_constructor(uint8_t sign, uint64_t n_blocks, ...) {
	ubint *number;
	number = (ubint *)malloc(sizeof(ubint));
	number->blocks = (uint32_t *)malloc(sizeof(uint32_t[n_blocks]));

	va_list blocks;
	va_start(blocks, n_blocks);

	for(uint64_t i = 0; i < n_blocks; i++) {
		number->blocks[i] = va_arg(blocks, uint32_t);
	}
	number->sign = sign;
	number->n_blocks = n_blocks;

	return number;
}

void ub_destructor(ubint *number) {
	free(number->blocks);
	free(number);
}

uint64_t ub_pow(uint32_t index) {
	uint64_t res = 1;
	for(; index > 0; index--) {
		res = (res << 3) + (res << 1);
	}
	return res;
}

ubint *ub_string(char *num_string) {
	ubint *number = (ubint *)malloc(sizeof(ubint));

	uint64_t n_digits = strlen(num_string);
	
	if(num_string[0] == '-') {
		number->sign = 1;
		num_string++;
		n_digits -= 1;
	}
	else {
		number->sign = 0;
	}

	number->n_blocks = (uint64_t)ceill((long double)n_digits / 9.632);
	printf("n_blocks = %lu \n", number->n_blocks);
	number->blocks = (uint32_t *)malloc(sizeof(uint32_t[number->n_blocks]));

	uint64_t pos = n_digits - 1;
	uint64_t tmp = 0, index = number->n_blocks - 1;
	uint32_t block;
	uint8_t break_flag = 0;

	
/* BUGGY BLOCK
	while(break_flag < 2) {
		for(uint32_t i = 0; tmp < 0xffffffff && break_flag < 2; i++) {
			if(pos == 0) {
				break_flag++;
			}
			else {
				tmp += (uint64_t)((num_string[pos--] - '0') * ub_pow(i));
				printf("tmp = %016lx \n", tmp);
			}
		}
		block = (uint32_t)(tmp & 0xffffffff);
		printf("block[%lu] => %08x \n", index, block);
		number->blocks[index--] = block;
		tmp = tmp >> 32;
	}
*/

	return number;
}

void ub_print(ubint *number) {
	if(number->sign)
		printf("-");

	printf("%08x", number->blocks[0]);
	for(uint64_t i = 1; i < number->n_blocks; i++) {
		if(number->blocks[i] != 0) {
			printf("%08x", number->blocks[i]);
		}
	}
}
