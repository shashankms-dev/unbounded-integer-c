# unbounded-integer
C library for arbitrary sized integers

The number is stored in an array as blocks of unsigned 32-bit integers.
This makes performing arithmetic operations on these numbers faster and easier as compared to storing the number as a string of digits.

The size of the number is limited only by the availability of system memory.

Arithmetic operations such as addition, subtraction, multiplication, division, modulo, exponentiation etc. are defined on unbounded integers
