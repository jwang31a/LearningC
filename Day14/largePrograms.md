# writing large programs

* how to write programs with multiple source files and header files, each with their own purpose

## source files

* source file: extension .c, contains part of program, like functions and variables
    * one source file contains main, which is starting point for program
* example: reverse polish notation calculator
    * one file for reading tokens (number/operator)
    * one file for stack functions
    * main function has its own file
* dividing functions and variables into separate files clarifies structure of program
* allows greater reusability
* separate compilation (nice for large programs that change frequently)

## header files

* #include directive shares information (function prototypes, macro definitions, type definitions, etc.) between source files
* header files have .h extension
* in this textbook, source files are .c files

### #include directive

* `#include <filename>` for c's library
    * searches directory in which system header files reside
* `#include "filename"` for header files we write
    * search current directory, then directory in which system header files reside
    * make sure no brackets
    * can include path (not treated as string literals which is good for the many \ used in paths)
        * usually not best practice to do this because of portability issues
        * relative paths are better than absolute
* -Ipath to modify search location
* also `#include tokens`, tokens is any sequence of preprocessing tokens
    * good for macro naming files
    * ```C
        #if defined(IA32)
            #define CPU_FILE "ia32.h"
        #elif defined(IA64)
            #define CPU_FILE "ia64.h"
        #elif defined(AMD64)
            #define CPU_FILE "amd64.h"
        #endif

        #include CPU_FILE
        ```

### sharing macro definitions and type definitions

* shared macro and type definitions between files should be put into header files
    * inside boolean.h
    * ```C
        #define BOOL int
        #define TRUE 1
        #define FALSE 0
        ```
    * `#include "boolean.h"` in any files that require this type definition and macro
    * ```C
        #define TRUE 1
        #define FALSE 0
        typedef int Bool;
        ```
* saves time, easier modification, no worries about inconsistencies

### sharing function prototypes

* put function f's prototype in a header file, include header file in all places where f is called
* stack.c contains definitions for its functions
    * prototypes stored in stack.h
    * ```C
        void make_empty(void);
        int is_empty(void);
        int is_full(void);
        void push(int i);
        int pop(void);
        ```
    * stack.h must be included in something like calc.c, which contains the main function for a calculator

### sharing variable declarations

* `int i;` declares i and defines it as well
    * declares i a variable of type int
    * defines i because compiler sets space aside for i
* `extern int i;` only declares it (i is defined elsewhere in program)
    * extern works for all types
    * `extern int a[];` means we don't say what a's length is yet because no space is allocated
* to share variable, define it in one file: `int i;`
    * if needs to be initialized, initialize it here
    * other files contain declarations `extern int i;`
* declarations of shared variables put in header files

### nested includes

* header file may contain #include
* nested includes are fine now, but used to be bad practice or not allowed

### protecting header files

* if file1.h includes file3.h, file2.h includes file3.h and prog.c includes both file1.h and file2.h, when prog.c is compiled, file3.h is compiled twice
    * if file contains only macro definitions, function prototypes, variable declarations, no problem
    * but if file contains type definition, compilation error
* protect header files
    * enclose contents of file in #ifndef-#endif pair
    * ```C
        #ifndef BOOLEAN_H
        #define BOOLEAN_H

        #define TRUE 1
        #define FALSE 0
        typedef int Bool;

        #endif
        ```
    * when included the first time, macros aren't defined, so lines betwen the #ifndef #endif can stay
    * when included the second time, preprocessor removes those lines

### #error directives in header files

* if file requires feature from a specific standard for example, it might be good to have #error directive
    * ```C
        #ifndef __STDC__
            #error This header requires a Standard C compiler
        #endif

## dividing program into files

* simple program divided into files:
    * foo.c includes foo.h
    * foo.h with prototypes for foo.c functions

### text formatting

* input redirection
    * `justify <quote` from the command prompt
    * `justify <quote >newquote` output redirection, whatever justify outputs will go into a newquote file
* assumption that all words will be no longer than 20 chars (including punctuation)
* justifying line adds extra spaces between words so each line has same length (60 chars)
* all functions related to words in word.c
* line buffer in line.c (as lines are written only if they're full or approximately full)
* justify.c contains main function
* word.h and line.h contain prototypes for functions in corresponding source file

## building multiple file program

* each source file compiled separately (header files don't need to be compiled, auto compiled if source file including it compiled)
    * source file compiled to object code in object files (.o extension in UNIX and .obj in windows)
* linking linker combines object files along with code for library functions to produce executable file
    * resolves external references left behind by compiler
    * external reference occurs when function in one file calls function defined in another file or accesses variable defined in another file
* to compile the text formatting program:
    * `gcc -o justify justify.c line.c word.c`
    * 3 files compiled into object code, then linked into single file

### makefiles

* putting names of source files gets tedious
* recompiling all files also wastes time
* makefile: file containing information necessary to build program
    * lists files that are parts of program
    * describes dependencies: foo.c includes bar.h, so foo.c depends on bar.h
        * chnage to bar.h requires recompilation of foo.c
    * in the makefile, there are 4 rules
        * first line gives a target file, followed by dependencies
        * second line is command to be executed if target needs to be rebuilt b/c of change of dependent files
        * first rule: justify executable is target, depends on justify.o, word.o, line.o
            * command tells us how to rebuild and link
        * second rule: justify.o needs rebuild if change to justify.c, word.h, line.h
            * command tells compiler to compile justify.c into object file but not to link it
* make utility to build or rebuild program
    * make also determines which files are out of date
    * commands in makefile preceded by tab character
    * makefile stored in file named `Makefile` or `makefile`
    * to invoke make, `make target` (`make justify`)
* not everyone uses makefiles

### errors during linking

* some errors detected during compilation can be found during linking
    * if definition of function or variable missing from program, unable to resolve external references
    * undefined symbol, undefined reference
* common causes:
    * misspellings: if name of variable or function misspelled, linker reports as missing
    * missing files: if linker can't find functions in foo.c, it might not know about the file
        * check makefile or project file to make sure foo.c is listed
    * missing libraries: linker may not be able to find all library functions used in program, like with the \<math.h\> header
        * including header in program may not be enough, may require the -lm option when program linked

### rebuilding program

* rare to recompile all files, rebuilding only recompiles files affected by latest change
* since we only modified word.c and justify.c, we rebuild using `gcc -o justify justify.c word.c line.o`
    * line.o instead of line.c because line hasn't been changed
    * makefile handles rebuilding automatically

### defining macros outside program

* can specify value of macro at time of compilation using -D option
    * this makes it easy to change value of macro without editing program files
    * `gcc -DDEBUG=1 foo.c` defines DEBUG macro to value 1 in foo.c as if `#define DEBUG 1` was at beginning of foo.c
    * -U option undefines macro