# type conversion in C

## basic types can be mixed in expressions

* conversion of smaller type to larger type (usually through implicit conversions)
* also explicit conversions

### implicit conversions

* when operands in arithmetic/logical expression don't have same type (usual arithmetic conversions)
* when type of expression on right of assignment doesn't match type of variable on left side
* when type of argument in function call doesn't match type of corresponding parameter
* when type of expression in return doesn't match return type

### usual arithmetic conversions

* float + int: easier to convert int to float instead of float to int (loss of precision)
* type is narrower if it requires fewer bytes to store
* convert narrower type to type of other operand (promotion)
    - integral promotions: character or short to int (unsigned int sometimes)
* if type of either operand is floating type:
    - float < double < long double
* neither operand is floating type
    - integral promotion on both operands
    - int < uint < long < ulong
    - special case of when long and uint have same length: both converted to ulong
* beware comparison between unsigned and signed (compiler may warn)
* assigning wide type to narrower variable type will drop information (or warning)

### C99 integer conversion rank

1) long long, unsigned long long
2) long, unsigned long
3) int, uint
4) short, ushort
5) char, signed char, uchar
6) _Bool

### casting

* sometimes manual type conversion can be useful, so we cast data
* cast expression (type)
* can help avoid overflow with narrower data types

## type definitions

* #define macro
* better way is 
* `typedef int Bool;`
* type definitions give more information and help with future modifications
* also helps with portability since types may have different ranges depending on machine
* <stdint.h> to define names for integer types with specific number of bits, helps with portability

## sizeof operator
* `sizeof (typename)`
* determines amount of memory required to store values of particular type in bytes
* parentheses not required but helps when used with expressions
* sizeof is unary, takes precedence over binary operations
* sizeof expression type is size_t, so something like `printf("Size of int: %zu\n", sizeof(int));` will work (z required)