#include <stdio.h>
#include "ub_int.h"

int main() {
	ubint_t num = ub_constructor(0, 8, 0x00, 0x00, 0x00, 0xd8391fff08cf732a, 0x1994bc44b4fa9c7d, 0x00, 0xe466a289c91f132d, 0x13d4c6baa7fef345);
	ub_print(num);
}
