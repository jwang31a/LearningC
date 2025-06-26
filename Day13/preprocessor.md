# preprocessor

* define and include directives are handled by preprocessor, which edits programs before compilation
* C and C++ rely on preprocessor

## how preprocessor works

* preprocessing directives are commands start with #
* #define directives defines macro: name that represents something else like a constant or frequently used expression
    * preprocessor stores the name of macro with definition
    * when macro used, preprocessor expands macro with defined value
* #include tells preprocessor to open file and include its contents as part of file being compiled
    * `#include <stdio.h>` instructs preprocessor to open stdio.h and bring content into program
* C program -> preprocessor -> modified C program -> compiler -> object code
* output of the preprocessor removes directives and includes specified from directives
* before preprocessor:
    * ```C
        /*converts f to c*/
        #include <stdio.h>
        #define FREEZING_PT 32.0f
        #define SCALE_FACTOR (5.0f / 9.0f)

        int main(void) {
            float fahrenheit, celsius;
            printf("Enter Fahrenheight temperature: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - FREEZING_PT) * SCALE_FACTOR;
            printf("Celsius equivalent is: %.lf\n", celsius);
            return 0;
        }
        ```
* after preprocessor:
    * ```C
        blank line
        blank line
        lines brought from stdio.h
        blank line
        blank line
        blank line
        blank line
        int main(void) {
            float fahrenheit, celsius;
            printf("Enter Fahrenheit temperature: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32.0f) * (5.0f / 9.0f);
            printf("Celsius equivalent is: %.lf\n", celsius);
            return 0;
        }
        ```
    * replaces directive lines with blanks
* preprocessor used to separate program, but now is part of compiler and output may not be C code
    * gcc generates preprocessor output with -E option
* preprocessor doesn't really know C so it can create illegal programs

## preprocessing directives

* macro definition: #define
    * #undef removes macro definition
* file inclusion: #include
* conditional compilation: #if, #ifdef, #ifndef, #elif, #else, #endif
    * these allow blocks of text to be included or excluded from program
* all directives start with #
* any number of spaces and horizontal tab characters may separate tokens in directive
    * `#    define      N       100` is a legal directive
* directives ennd at first newline character, unless explicitly continued
    * ```C
        #define DISK_CAPACITY (SIDES * \
                               TRACKS_PER_SIDE * \
                               SECTORS_PER_TRACK * \
                               BYTES_PER_SECTOR)
        ```
* directives can appear anywhere in program
    * define and include usually show up at beginning, other directives can even be in middle of function
* comments may appear on same line as directive: usually good practice to explain meaning of macro

## macro definitions

* simple macros have no parameters
* parameterized macros also supported

### simple macros

* simple macro or object-like macro has form:
    * `#define identifier replacement-list`, replacement-list is any sequence of preprocessing tokens
    * can replacce with identifiers, keywords, numeric or character constants, string literals, operators, punctuation
* don't put extra symbols
    * ```C
        #define N = 100
        ...
        int a[N]; //becomes int a[= 100]
        ```
    * ```C
        #define N 100;
        ...
        int a[N]; //becomes int a[100;]
* macros advantages:
    * programs easier to read, if macro name is well chosen compared to "magic numbers"
    * programs easier to modify: if constant is used multiple times, changing macro name will change all occurrences
    * avoids inconsistencies and typographical errors: if constant appears many times in program, avoids possibility that one constant is mistyped
* other applications
    * can also make minor changes to synatx of C
        * #define BEGIN {
        * #DEFINE END }
        * can even redefine everything, although it's a bad idea
    * renaming types, although type definitions are superior
    * controlling conditional compilation, i.e. debug mode with extra statements

### parameterized macros

* parameterized macro or function-like macro
    * `#define identifier(x1, x2, ..., xn) replacement-list
    * no space between macro name and left parenthesis
    * ```C
        #define MAX(x, y) ((x) > (y) ? (x) : (y))
        #define IS_EVEN(n) ((n) % 2 == 0)
        i = MAX(j + k, m - n);
        if (IS_EVEN(i)) i++;
        ```
    * ```C
        i = ((j + k) > ( m - n) ? (j + k) : (m - n));
        if (((i) % 2 == 0)) i++;
    * all of these parenthesis are necessary
    * macros are nice for simple functions
    * ```C
        #define TOUPPER(c) ('a' <= (c) && (c) <= 'z' ? (c) - 'a' + 'A' : (c))
        ```
    * also empty parameter list
        * `define getchar() getc(stdin)`
* advantages:
    * possibly slightly faster because no function call needed, macro invocation is lighter
        * C99 inline functions avoids overhead without macros
    * macros are "generic": don't specify type, so macros can be used for many different types
* disadvantages:
    * larger compiled code because of replacement list
    * arguments not type-checked
    * cannot have pointer to macro, pointers to function are often useful (macros removed during preprocessing so pointer to nothing doesn't make sense)
    * macro may evaluate arguments more than once
        * ```C
            n = MAX(i++, j);
            n = ((i++) > (j) ? (i++) : (j));
            ```
        * this causes i to be incremented twice
* parameterized macros also good for patterns for repeated segments of code
    * `#define PRINT_INT(n) printf("%d\n", n)`

### the # operator

* the # and ## operators executed during preprocessing
* the # operator converts macro argument into string literal (stringization)
* `#define PRINT_INT(n) printf(#n " = %d\n", n)`
* `PRINT_INT(i / j);` converted to `printf("i / j" " = %d\n", i / j);`, but due to string joining by the compiler, it'll appear finally as `printf("i / j = %d\n", i / j);`

### the ## operator

* the ## operator "pastes" two tokens together to form single token (## known as token-pasting)
* ```C
    #define MK_ID(n) i##n
    int MK_ID(1), MK_ID(2), MK_ID(3);
    ```
* converted to `int i1, i2, i3;`
* not freuqently used
* max macro doesn't behave properly if arguments have side effects, also may need type specificity
    * ```C
        #define GENERIC_MAX(type) \
        type type##_max(type x, type y) \
        {
            return x > y ? x : y;
        }
        ```
    * now if we need a max function that works with floats,
    * `GENERIC_MAX(float)` becomes `float float_max(float x, float y) {return x > y ? x : y;}

### general properties of macros

* macros's replacement list may contain invocations of other macros
    * ```C
        #define PI 3.14159
        #define TWO_PI (2*PI)
        ```
* replaces entire tokens, not portions of tokens
    * ```C
        #define SIZE 256
        int BUFFER_SIZE;
        if (BUFFER_SIZE > SIZE)
            puts("Error: SIZE exceeded");
        ```
    * ```C
        int BUFFER_SIZE;
        if (BUFFER_SIZE > 256)
            puts("Error: SIZE exceeded");
        ```
    * notice that BUFFER_SIZE and the string remain unchanged
* macro definition normally remains in effect until end of file, normal scope rules
* macro may not be defined twice unless new definition is identical to old one (identical tokens and parameters)
* macros can be undefined by #undef directive
    * `#undef identifier`
    * no effect if no definition exists

### parentheses

* if macro's replacement list contains operator, enclose replacement list with parentheses
    * `#define TWO_PI (2 * 3.14159)`
    * `#define SCALE(x) ((x)*10)
    * without parentheses, operator precedence may not happen as intended

### creating longer macros

* `#define ECHO(s) (gets(s), puts(s))` lets us make replacement list a series of expressions
* try to redefine as `#define ECHO(s) {gets(s); puts(s);}`
    * but this is problematic:
    * ```C
        if (echo_flag)
            ECHO(str);
        else
            gets(str);
        ```
    * ```C
        if (echo_flag)
            {gets(str); puts(str);};
        else
            gets(str);
        ```
    * the if statement is treated as a full if statement b/c of semicolon that follows (null statement)
    * then the else is not attached to anything
* comma operator solves problem when we need a series of expressions, but not with a series of statements
    * workaround is a do while loop which will run exactly once (false condition)
    * ```C
        #define ECHO(s)      \
                do {         \
                    gets(s); \
                    puts(s); \
                } while (0)
        ```
    * then each call of ECHO must be followed with semicolon to complete the do statement

### predefined macros

* \_\_LINE\_\_: line number of file being compiled
* \_\_FILE\_\_: name of file being compiled
* \_\_DATE\_\_: date of compilation (mmm dd yyyy)
* \_\_TIME\_\_: time of compilation (hh:mm:ss)
* \_\_STDC\_\_: 1 of compiler conforms to C standard (C89 or C99)
* date and time can be useful for distinguishing among different versions of the same program
* line and file macros for locating errors
    * ```C
        #define CHECK_ZERO(divisor) \
            if (divisor == 0) \
                printf("*** Attempt to divide by zero on line %d " \
                "of file %s ***\n", __LINE__, __FILE__)
        
        CHECK_ZERO(j);
        k = i / j;
        ```
    * C library has macros named assert

### additional C99 macros

* \_\_STDC__HOSTED\_\_: 1 if hosted implementation, 0 if freestanding
    * implementation of C consists of compiler plus software necessary to execute C programs
    * hosted must accept any program that conforms to C99 standard
    * freestanding doesn't have to compile programs that use complex types or standard headers beyond basic
        * does not have to support stdio.h
* \_\_STDC__VERSION\_\_: version of C standard supported (199409L for C89, 199901L for C99, different values for each amendment to standard)
* \_\_STDC_IEC_559\_\_: 1 if IEC 60559 floating point arithmetic supported
* \_\_STDC_IEC_559_COMPLEX\_\_: 1 if IEC 60559 complex arithmetic supported
* \_\_STDC_ISO_10646\_\_: yyyymmL if wchar_t values match ISO 10646 standard of specified year and month

### empty macro arguments

* any or all arguments in macro call can be empty, but will contain same number of commas as in normal call
* ```C
    #define ADD(x, y) (x + y)
    i = ADD(j, k); //becomes (j + k)
    i = ADD(, k); //becomes (+ k)
    ```
* ```C
    #define MK_STR(x) #x
    char empty_string[] = MK_STR(); //becomes ""
    ```
* ```C
    #define JOIN(x, y, z) x##y##z
    ...
    int JOIN(a, b, c), JOIN(a, b,), JOIN(a,,c), JOIN(,,c);
    //becomes abc, ab, ac, c
    ```
    * missing arguments replaced with placemarker tokens which disappear

### macros with variable number of arguments

* macros can take unlimited number of arguments, like in functions
* ```C
    #define TEST(condition, ...) ((condition) ? \
        printf("Passed test: %s\n", #condition): \
        printf(__VA_ARGS__))
    ```
    * ... token (ellipsis) goes at end of parameter list, preceded by ordinary parameters
    * \_\_VA_ARGS\_\_ is special identifier that can only appear in replacement list of macro with variable number of arguments
        * represents all arguments that correspond to ellipsis
        * at least one argument corresponds to ellipsis, empty argument allowed
        * therefore TEST macro requires at least 2 arguments, one for condition, remaining match ellipsis
* ```C
    TEST(voltage <= max_voltage,
        "Voltage %d exceeds %d\n", voltage, max_voltage);
    ```
* replaced with:
* ```C
    ((voltage <= max_voltage)?
        printf("Passed test: %s\n", "voltage <= max_voltage"):
        printf("Voltage %d exceeds %d\n", voltage, max_voltage));

### \_\_func\_\_ identifier

* \_\_func\_\_ isn't related to preprocessing, but useful for debugging
* every function has access
* behaves like string variable that stores name of currently executing function
* sort of like if this were at beginning of function body:
    * ```C
        static const char __func__[] = "function-name";
        ```
    * ```C
        #define FUNCTION_CALLED() printf("%s called\n", __func__)
        #define FUNCTION_RETURNS() printf("%s returns\n", __func__)
        //the textbook puts semicolons at the end of the macros but i don't think that's good practice is it?
        void f(void) {
            FUNCTION_CALLED(); //displays "f called"
            ...
            FUNCTION_RETURNS(); //displays "f returns"
        }
        ```

## conditional compilation

* conditonal compilation, inclusion or exclusion of section of program text depending on outcome of test performed by processor

### #if and #endif directives

* for example let's say we're using printf statements to debug, but the moment we're done debugging, we don't use the printf statements
* ```C
    #define DEBUG 1
    ...
    #if DEBUG
    printf("Value of i: %d\n", i);
    printf("Value of j: %d\n", j);
    #endif
    ```
    * if will test value of DEBUG, since value isn't 0, preprocessor will leave the calls of printf
    * but if value of DEBUG is 0, preprocessor will remove all four lines from program
* #if constant-expression
* #endif
* undefined identifiers as macros have value 0, so if DEBUG is not defined, test will fail (no error), while `#if !DEBUG` will succeed

### defined operator

* defined operator produces value 1 if identifier is currently defined macro, 0 otherwise
* ```C
    #if defined(DEBUG)
    ...
    #endif
    ```
* ```C
    #if defined DEBUG
    ```

### #ifdef and #ifndef directives

* #ifdef tests whether identifier currently defined
    * `#ifdef identifier` equivalent to `#if defined(identifier)`
* #ifndef similar to #ifdef, but tests whether identifier is not defined as macro
    * `#ifndef identifier` equivalent to `#if !defined(identifier)`

### #elif and #else directives

* `#elif constant-expression`
* `#else`
* ```C
    #if expr1
    ...
    #elif expr2
    ...
    #else
    ...
    #endif
    ```

### uses of conditional compilation

* common applications
    * portable programs for several machines or operating systems
        * macro for windows, macos, linux, with code specific for each os
    * writing programs that can be compiled with different compilers using the \_\_STDC\_\_ macro
        * ```C
            #if __STDC__
            function prototypes
            #else
            old-style function declarations
            #endif
            ```
    * providing default definition for macro
        * checks if a macro is defined, if not, define it
        * ```C
            #ifndef BUFFER_SIZE
            #define BUFFER_SIZE 256
            #endif
            ```
    * temporarily disabling code that contains comment
        * can't use \/\*\*\/ to comment out code that already contains \/\*\*\/
        * ```C
            #if 0
            lines containing comments
            #endif
            ```
        * conditioning out

## misc directives

* error, line, pragma directives

### #error directive

* `#error message`, message is any sequence of tokens
    * prints error message which includes message, exact form can vary from one compiler to another
* encountering error directive indicates serious flaw, some compilers immediately terminate compilation without attempting to find other errors
* used in conjunction to with conditional compilation to check for situations that shouldn't arise in normal compilation
* for example if we want ints up to a certain type,
    * ```C
        #if INT_MAX < 100000
        #error int type is too small
        #endif
        ```
* ```C
    #if defined(WIN32)
    ...
    #elif defined(MAC_OS)
    ...
    #elif defined(LINUX)
    ...
    #else
    #error No operating system specified
    #endif
    ```

### #line directive

* `#line` used to alter the way program lines are numbered
* `#line n`, n must be sequence of digits representing integer between 1 and 32767 (2147483647 C99)
    * causes subsequent lines to be numbered n, n + 1, n + 2
* `#line n "file"
    * lines that follow assumed to come from file, with line numbers starting at n
* changes value of \_\_LINE\_\_ macro
* for example, `#line 10 "bar.c"` at beginning of foo.c
    * if error on line 5 of foo.c, error message will refer to line 13 of bar.c
    * this is super confusing wtf
        * line 1 foo.c (directive)
        * line 2 foo.c = line 10 bar.c
        * line 3 foo.c = line 11 bar.c
        * line 4 foo.c = line 12 bar.c
        * line 5 foo.c = line 13 bar.c, this is where the line 13 comes from
    * not very useful normally, although it can help with programs that generate C code as output

### #pragma directive

* requests special behavior from compiler, usually for unusually large programs or to use cpaabilites of compiler
* `#pragma tokens`, tokens are arbitrary tokens
    ```C
        #pragma data(heap_size => 1000, stack_size => 2000)
        ```
* commands allowed depends on compiler
* C99 STDC first token following `#pragma`
    * FP_CONTRACT
    * CX_LIMITED_RANGE
    * FENV_ACCESS

### _Pragma operator

* C99 _Pragma operator, used with #pragma directive
* `_Pragma (string-literal)`
* preprocessor "destringizes" string literal
* ```C
    _Pragma("data(heap_size => 1000), stack_size => 2000")
    ```
* equivalent to
* ```C
    #pragma data(heap_size => 1000, stack_size => 2000)
    ```
* works around limitation of preprocessor: preprocessing directive can't generate another directive, but _Pragma is an operator
* ```C
    #define DO_PRAGMA(x) _Pragma(#x)
    DO_PRAGMA(GCC dependency "parse.y") //outcome #pragma GCC dependency "parse.y"
    ```

## q&a

* \# can be on a line by itself, called null directive
* the # operator stringizes " to \" and \ to \\\
* nested stringizes don't work normally
    * ```C
        #define CONCAT(x, y) x##y
        CONCAT(a, CONCAT(b, c)) //yields aCONCAT(b, c)
        ```
* solution is to define a macro that calls the first
    * ```C
        #define CONCAT2(x, y) CONCAT(x, y)
        CONCAT2(a, CONCAT2(b, c))
        ```