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