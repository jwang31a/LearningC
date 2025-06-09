#include <stdio.h>
#include <limits.h> //macros for smallest and largest values of each integer type

int main(void) {
    return 0;
}

/*
number types: integers and floating points
integer types:
  - signed integers leftmost bit is the sign bit (0 positive or zero, 1 negative)
  - unsigned integers have no sign bit, always positive (unsigned keyword)
  - default int is 32 bits
  - long int is double the bits
  - short int is half the bits
  - exact bit number is not standard between compilers
  - C99 also includes long long ints
decimal in base 10
  - must not begin with a 0
octal in base 8
  - must begin with a 0
hexadecimal in base 16
  - must begin with a 0x
  - digits include 0 through 9 and characters a through f
octal and hexadecimal just different ways of writing the same number
  - good for low level programs
  - numbers stored in binary anyway
to treat constant as a long, suffix L (or l)
to indicate unsigned constant, put letter U (or u)
overflow happens when result is too large to represent as its original type
  - signed overflow -> undefined behavior
  - unsigned overflow -> correct answer modulo 2^n, n=# of bits used to store result
for unsigned integers, use u, o, or x instead of d in conversion specification
for shorts, put h in front
for longs, put l in front
for long long, put ll
*/