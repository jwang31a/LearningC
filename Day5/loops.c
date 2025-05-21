#include <stdio.h>

int main(void) {
    int i = 1;
    int n = 100;
    printf("==========while loop==========\n");
    /*
    the controlling expression is false when while loop terminates
    loop may not be executed at all due to controlling expression being tested before
    beware infinite loops (C will not exit for you)
    */
   while (i < n) {
       printf("%i = d\n", i);
       i *= 2;
    }
    // while (1) {
        //     printf("infinite loop\n");
        // }
    printf("==========do while loop==========\n");
    i = 10;
    do {
        printf("T minus %d and counting\n", i--);
    } while (i > 0); //end with semicolon
    printf("==========for loop==========\n");
    for (i = 10; i > 0; i--) {
        printf("T minus %d and counting\n", i);
    }
    printf("==========for loop 2==========\n");
    i = 10; //variable initialization can be performed before loop
    for (; i > 0; --i)
        printf("T minus %d and counting\n", i);
    printf("==========for loop 3==========\n");
    for (i = 10 ; i > 0;) //decrementing can be done inside loop
        printf("T minus %d and counting\n", i--);
    printf("==========for loop 4 -> while loop==========\n");
    i = 10;
    for (; i > 0;) //omitting first and third expression makes a while loop
        printf("T minus %d and counting\n", i--);
    // printf("==========infinite loop==========\n");
    // for (;;) //defaults to a true value for infinite loop
    //     printf("Infinite loop goes brrrr\n");
    printf("==========declaration within for loop==========\n");
    for (int j = 10; i > 0; i--) //this version of j is only located in the loop (local scope)
    printf("T minus %d and counting\n", i);
    // printf("%d\n", j); //compiler has no clue where this j comes from
    return 0;
}

/*
while, do, for:
  - while statement used for loops whose controlling expression tested before loop body executed
  - do statement used if expression tested after loop body executed
  - for statement convenient for loops that increment or decrement counting variable
  - comma operator (primarily used in for statements)
break, continue, goto:
  - break jumps out of loop and transfers control to next statement after loop
  - continue skips rest of loop iteration
  - goto jumps to any statement within function
  - null statement, loops with empty bodies

do while loops:
  - loop body executed first, then controlling expression evaluated
  - terminates when controlling expression has value 0
  - loop body always executed at least once
for loops:
  - can generally be replaced with a while loop
  - expressions can be omitted in for statement

exiting from loop:
  - break statement jumps out of statements (switch and loops)
      - good for earlier break conditions in the middle of body
      - only escapes 1 level of nesting
  - continue statement doesn't exit loop, instead transfers control to just before end of loop body
      - limited to use in loops

if for loop contains continue, it can no longer be converted into a while statement using the common pattern
for (;;) historically preferred for infinite loops due to efficiency
  - modern compilers should have no difference
goto statements are fine, but can lead to spaghetti code where control jumps
*/