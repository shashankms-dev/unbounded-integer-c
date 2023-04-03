#include <stdio.h>
#include <stdlib.h>
#include "src/ubint.h"

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <large_number> \n", argv[0]);
        return EXIT_FAILURE;
    }

    ubint *number = ub_hex_string(argv[1]);
    
    ub_print(number);
    printf("\n");
    ub_destructor(number);
}