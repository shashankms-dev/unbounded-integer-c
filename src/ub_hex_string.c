#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "ubint.h"

ubint *ub_hex_string(char *num_string) {
    ubint *num = malloc( sizeof(ubint) );

    uint64_t n_digits = strlen(num_string);

    if(num_string[0] == '-') {
        num->sign = 1;
        num_string++;
        n_digits -= 1;
    }
    else {
        num->sign = 0;
    }

    num->length = ceill((long double) n_digits / 8);
    num->blocks = malloc(sizeof( uint32_t[num->length] ));

    uint64_t pos = n_digits;
    uint64_t index = num->length - 1;
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
            num->blocks[index--] = block;
            block = 0;
        }
    }

    return num;
}

