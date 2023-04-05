#include <stdio.h>
#include <stdlib.h>
#include "src/ubint.h"

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Usage: %s <large_number_1> <large_number_2> \n", argv[0]);
        return EXIT_FAILURE;
    }

    ubint *num1 = ub_hex_string(argv[1]);
    ubint *num2 = ub_hex_string(argv[2]);
    
    ubint *res = ub_add(num1, num2);

    ub_print(num1);
    printf("\n");
    
    ub_print(num2);
    printf("\n");
    
    ub_print(res);
    printf("\n");

    ub_destructor(num1);
    ub_destructor(num2);
    ub_destructor(res);

}
