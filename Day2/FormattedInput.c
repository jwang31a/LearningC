#include <stdio.h>

int main(void) {
    int i, j;
    float x, y;
    //if instead of inputting numbers separated by whitespace, i enter something like this:
    //1-20.3-4.0e3, the rules of scanf will actually read 4 numbers from this
    scanf("%d%d%f%f", &i, &j, &x, &y);
    printf("|%d|%d|%f|%f|\n", i, j, x, y);
    //format strings can include ordinary characters: here / is allowed but any unpredictable spaces cause problems
    //spaces can be put in the specification to accommodate that
    scanf("%d/%d", &i, &j);
    printf("|%d|%d|\n", i, j);
    return 0;
}

/*
it looks like gcc and some other compilers will catch the typo where & is not in front of the variable name (scanf expects 4 int pointers, gets int)
these values do not necessarily have to be on the same line, but should be separated by white space of some kind (newline, space, tab, etc)
program will exit early and display strange values if we input the wrong data type
scanf searches for a digit or a plus/minus sign, reads digits until nondigit
the final newline is peeked at, but not actually read and left for the next scanf to read
%e, %f, %g interchangeable in scanf for recognizing floating point number
printf and scanf work in slightly different ways: their conversion specifications are different

small digression: %E, %F, %G (same thing but capitalized) do the exact same thing but print any alphabetical characters as uppercase
*/