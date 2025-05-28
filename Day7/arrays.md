# arrays

instead of scalar variables, we can store aggregate variables, which store collections of values

## 1d arrays

* array: data structure containing number of data values of the same type
* values are called elements, selected by position
* `int a[10];` for an array with 10 elements
    - macro for fixed length is good practice
    - ```C
        #define N 10
        ...
        int a[N];```

### subscripting

* access using index in square brackets
* whatever i know how arrays work
* for loops and arrays usually go together
* subscript bounds may not be checked, undefined behavior out of range

### initialization

* `int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};`
    - if initializer shorter than array, remaining elements given default value 0
    - `int a[10] = {0};` for all 0s (b/c initializer can't be empty)
    - length can be ommitted with an initializer

### C99 designated initializers

* designated initializers help with setting specific values while other values default to 0
    - `int a[15] = {[2] = 29, [9] = 7, [14] = 48};`
    - each number in brackets is called designator
    - order of elements doesn't matter
* if length given, designator from 0 to n - 1
    - if length not given, compiler deduces length from largest designator
* initializer can combine both element by element and designators

### sizeof with arrays

* sizeof on an array gives the total size of the array
* sizeof on element in array gives size of an element
* length is sizeof array / sizeof element
* good for clearing an array when the size may fluctuate
    - ```C
        for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
            a[i] = 0;
        ```
    - compilers may get angry b/c sizeof returns a value of type size_t, so manual typecast to int
    - then, probably best to define a macro for easier portability and reusability

## multidimensional arrays

* a 2d array is a matrix
    - ```C
        int m[5][9];
        ```
    - 5 rows 9 columns
    - you know how 2d arrays and matrices work i'm skipping the details
* 2d array is not stored as a table in memory, but as row after row
* nested for loops good for multidimensional arrays

### initializing multidimensional arrays

* initializer uses nested 1d initializers
* if initializer not long enough, last rows will contain 0s
    - or remaining elements will be 0
* inner braces can even be omitted and values will fill next row once one row fills
    - (risky, compiler may warn)
* C99 designated initializers also work

### constant arrays

* any array can be made constant and should not be modified by program
* const keyword not limited to arrays, can be used with other types

## variable length arrays (C99)

* length of array may be a non constant expression (determined by variable)
* look at reverse2.c for example
* program decides how long the array is
    - allows less hardcoding, which can be inefficient or cause failure within the program
* can also be multidimensional