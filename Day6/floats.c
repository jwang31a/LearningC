#include <stdio.h>
#include <float.h>

int main(void) {

    return 0;
}

/*
IEEE standard
float is single precision
  - useful for when high precision is not critical
  - about 6 decimal digit precision
double is double precision
  - better precision, enough for most programs
  - 15 digit precision
long double is extended precision floating point
  - top precision, but rarely used
C standard doesn't state precision of these types
also includes complex types
  - float _Complex
  - double _Complex
  - long double _Complex
floating point literals default to double precision
hexadecimal floats exist, but rarely used
reading type of double, l in front of e, f, g
reading or writing value of long double, L in front of e, f, g
*/