#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ubint.h"

ubint *ub_constructor(uint8_t sign, uint64_t n_blocks, ...) {
	ubint *number;
	number = malloc( sizeof(ubint) );
	number->blocks = malloc( sizeof(uint32_t[n_blocks]) );

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
	ubint *number = malloc( sizeof(ubint) );

	uint64_t n_digits = strlen(num_string);
	
	if(num_string[0] == '-') {
		number->sign = 1;
		num_string++;
		n_digits -= 1;
	}
	else {
		number->sign = 0;
	}

	number->n_blocks = ceill( (long double)n_digits / 9.632 );
	number->blocks = malloc( sizeof(uint32_t[number->n_blocks]) );

	uint64_t pos = n_digits - 1;
	uint64_t tmp = 0, index = number->n_blocks - 1;
	uint32_t block;
	uint8_t first = 0;

	for(uint32_t i = 0; first == 0; i++) {
		if(pos == 0) first = 1;

		tmp += (num_string[pos--] - '0') * ub_pow(i);
		if(tmp >= 0xffffffff) {
			printf("block[%lu] = %08x \n", index, block);
			block = (uint32_t) tmp;
			tmp = tmp >> 32;
			number->blocks[index--] = block;
		}
		if(first) {
			printf("block[%lu] = %08x \n", index, tmp);
			number->blocks[index] = (uint32_t) tmp;
			break;
		}
	}

	return number;
}

ubint *ub_hex_string(char *num_string) {
	ubint *number = malloc( sizeof(ubint) );

	uint64_t n_digits = strlen(num_string);
	
	if(num_string[0] == '-') {
		number->sign = 1;
		num_string++;
		n_digits -= 1;
	}
	else {
		number->sign = 0;
	}

	number->n_blocks = ceill((long double) n_digits / 8);
	number->blocks = malloc(sizeof( uint32_t[number->n_blocks] ));

	uint64_t pos = n_digits;
	uint64_t index = number->n_blocks - 1;
	uint32_t block;
    uint32_t digit;
    uint32_t value, shift = 0;

	while(pos > 0) {
        digit = num_string[--pos];

        if(digit >= '0' && digit <= '9') {
            value = digit - '0';
        }
        else if(digit >= 'A' && digit <= 'F') {
            value = digit - 'A' + 10;
        }
        else {
            value = digit - 'a' + 10;
        }

        block += value << (shift * 4);
        shift = (shift + 1) % 8;

        if(shift == 0 || pos == 0) {
            number->blocks[index--] = block;
        }
	}

	return number;
}
void ub_print(ubint *number) {
	if(number->sign)
		printf("-");

	for(uint64_t i = 0; i < number->n_blocks; i++) {
		printf("%08x", number->blocks[i]);
	}
}
