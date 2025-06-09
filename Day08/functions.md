# functions yippee

## defining and calling functions

* sample average function (not in the C library, but easy to make)
    * ```C
        double average(double a, double b) {
            return (a + b) / 2;
        }```
    * return type, parameters, function body, you know how functions work
* ```C
    return-type function-name(parameters) {
        declarations
        statements
    }```
* specifying void means no return value
    * cannot omit void in C99 bc illegal things are illegal
* sometimes return type is on the line above the function name
    * useful for long return types
    * ```C
        unsigned long int
        average(unsigned long int a, unsigned long int b) {
            return (a + b) / 2;
        }```
* each parameter must have the type specified
    * void necessary if no parameters
* variables defined in function bocy belong exclusively to that function
* function call without parentheses has no effect
* return value of a non void function can be discarded if not needed (although it can be nice to store)
* you can also put void before the function call to cast to void as a way to say we don't care about the return value

## function declarations

* definition of function not required to precede calls
* when compiler sees the function call before the definition, it creates an implicit declaration of the function where it defaults to a return type of int and doesn't know the number of arguments or the types
* then compiler sees the definition ans error message
* declare each function before calling it
    * ```C
        return-type function-name (parameters);
* function prototypes (sort of like an interface, but without objects)
* either declaration or definition comes before a call

## arguments

* parameters appear in function definitions (dummy names that represent values when function called)
* arguments are expressions that appear in function calls
* arguments passed by value (value assigned to corresponding parameter)
    * arguments passed are copies so we can modify
* functions can only return 1 value, but what if we want to get multiple values?
    * we could try to modify the values themselves, but they only create copies
    * can be done but later

### argument conversions

* types of arguments don't need to match type of parameters
    * compiler encountered prototype before call
        * value of argument implicitly converted to type of corresponding parameter
    * compiler has not encountered prototype prior to call (default argument promotions)
    * relying on argument conversions are not reliable, should be careful

### array arguments

* ```C
    int f(int a[]) {
        ...
    }
    ```
* length of array unspecified if one dimensional
    * usually supply length as another argument
    * do not use the sizeof operator because it doesn't give the correct answer for an array parameter (discussed in later chapter)
    * probably because of pointer shenanigans
* function can change elements of array parameter and changes will be reflected in corresponding argument
* for multidimensional arrays, only length of first dimension may be omitted

### variable length array parameters

* we can state the length first and explitly state an array's length
* ```C
    int sum_array(int n, int a[n]) {
        ...
    }
* n cannot come before a[n]
* `int sum_array(int n, int a[*])` because parameter names optional, * indicates length related to a previous parameter
* also `int sum_array(int, int [])` is technically legal, although it doesn't show the relationship between n and a

### static

* keyword static
* ```C
    int sum_array(int a[static 3], int n)
* static indicates length of a guaranteed to be at least 3
* has no effect on behavior of the program, just a hint for the C compiler
* static can also only be used on the first dimension

### compound literals

* `total = sum_array((int []) {3, 0, 3, 4, 1}, 5);`
* create an unnamed array that does not exist anywhere else
* compound literals may contain arbitrary experssions

## return statement

* non void functions must return something
* can also ternary return
* implicit conversion to return type
* return statements not necessary in void functions, but they're nice sometimes
* also don't return an expression in a void function

## program termination

* main is also a function that returns ints
* C99 do not omit return type
* can omit void in parameter list, but it's cool to have
* return 0 is a status code which signifies normal termination

### exit function

* `exit(0)` means normal termination
    * 0 can be unclear, so `exit(EXIT_SUCCESS)` can be better
    * `exit(EXIT_FAILURE)` means abnormal termination
    * both defined in <stdlib.h>
* alternative to return statement in main

## recursion

* you know how recursion works with base cases and stuff and recursive stack
* C allows recursion although it doesn't happen all that often
* for some reason they decide to use quicksort as their example but it's probably cool for someone who's learning programming for the first time
