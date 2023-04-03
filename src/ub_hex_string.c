#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "ubint.h"

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
    uint32_t block = 0;
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
            block = 0;
        }
    }

    return number;
}

