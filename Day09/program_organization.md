# program organization

## local variables

* variable declared in function body is local to the function
* ```C
    int sum_digits(int n) {
        int sum = 0; //local
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    ```
* local variable properties:
    * automatic storage duration: storage duration or extent of variable is the portion of program execution during which storage for variable exists
        * automatic storage alocation (automatic storage duration)
    * block scope: scope is portion of program text in which variable can be referenced
        * local variable has block scope: visible from declaration to end of enclosing function body
        * declarations don't need to be at the beginning, so smaller scopes are possible

### static local variables

* static storage duration: permanent storage location, so value retention throughout execution of program
* ```C
    void f(void) {
        static int i;
        ...
    }
    ```
* when f returns, i won't lose its value
* still block scope, so retention for future calls
    * mainly useful for recursive functions probably

### parameters

* same properties for parameters
* except parameter initialized automatically when function is called

## external variables

* external variables: variables declared outside body of any function (global variables)
    * static storage duration
    * file scope: visible from declaration to end of file (by any function that follow its declaration)

### pros and cons

* if we change external variable, check all functions to see how change affects it
* if external assigned incorrect value, may be difficult to identify guilty function (or where the problem happened)
* functions that rely on external variables hard to reuse (not self-contained)

## blocks

* block scope variables: variable is local to the block in which it's declared
* you know how variable scope works

## scope

* when declaration inside block names identifier that's already visible, new declaration temporarily hides old one
    * at end of block, identifier regains old meaning
* ```C
    int i; //dec 1
    void f(int i) { //dec 2
        i = 1; //only matters for dec 2 (does not look at dec1)
    }

    void g(void) {
        int i = 2; //dec 3
        if (i > 0) {
            int i; //dec 4
            i = 3; //only deals with dec 4
        }
        i = 4; //only dec 3
    }

    void h(void) {
        i = 5;
    }
    ```
* variables look locally, then go out
* you know how scope works

## C program organization

* assumption that program fits inside single file (later chapter for multi file programs)
* program may contain:
    * preprocessing directives (include, define)
    * type definitions
    * declarations of extneral variables
    * function prototypes
    * function definitions