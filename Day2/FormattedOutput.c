#include <stdio.h>

int main(void) {
    int i = 10;
    int j = 128;
    int k = 2345678;
    float x = 1.128f;
    float y = 3838.1840f;
    float n = -1234.5678f;
    float bit32limit = 2147483647.123456;
    // printf("%d %d\n", i); //some compilers may not catch this but it looks like gcc does
    // printf("%d\n", i, j); //gcc will also catch this, but other compilers may not
    // printf("%f %d\n", i, x); //some compilers may let this go and print int as float, and truncate float to int, but not gcc
    printf("%3d\n", k); //since 2345678 has more than 3 chars, nothing is lost
    printf("%4d\n", i); //since 10 doesn't have 4 chars, it'll put 2 spaces to right justify
    printf("%.2e\n", y); //displays 3.83e+03 because only 2 chars after decimal specified
    printf("%g\n", bit32limit); //g chose e due to size, default 6 sig figs
    printf("%g\n", x); //g chose f due to moderate size
    printf("\n");

    i = 40;
    x = 839.21f;
    //first prints 40 as is
    //second displays 5 chars, so 3 spaces inserted before
    //third displays 5 chars as well, but left justified due to -, 3 spaces inserted after
    //fourth displays 5 chars but wants minimum of 3 digits displayed as well, 2 spaces and a 0 inserted in front
    printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
    //first displays 10 chars with minimum 3 digits after decimal, so 0 appended and 3 spaces inserted before (decimal point counts as char)
    //second displays 10 chars in exponential format with 3 after decimal point, so 1 space inserted before (the e+n counts as chars)
    //third displays 10 chars with g, left justified, so 4 spaces appended
    printf("|%10.3f|%10.3e|%-10g|\n", x, x, x);
    printf("\a\a\a\n"); //supposed to beep but i guess modern systems don't have consoles configured to make sound
    printf("Item\tUnit\tPurchase\n\tPrice\tDate\n"); //tabs are nice for formatting
    printf("\"Hello World!\"\n");
    printf("displays nothing\b\b\b\b\b\b\bsomething\n"); // /b doesn't delete characters, but moves cursor back 1 position so that any chars added will replace existing chars

    //cannot redeclare variables like this, good to know
    // int i, j;
    // float x, y;
}

/*
conversion specification form %m.pX
m is the minimum field width, or mininum number of characters to print
p is precision, and depends on X, conversion specifier
  - d displays decimal form, p indicates minimum number of digits to display (0s added to beginning, default 1)
  - e displays float in exponential format, p indicates how many digits after decimal point (default 6)
  - f displays float in fixed decimal format, p does same as in e
  - g displays float in either exponential or fixed decimal format, depending on size, p indicates max number of sig figs,
    will not show trailing zeros or decimal point if nothing past decimal
      - g is useful for when the size of number can't be predicted or when numbers may vary widely
      - g uses fixed decimal for moderately large or small numbers
      - g uses exponential for very large or small numbers
  - also other specifiers
*/

/*
extra escape sequences for now:
  - \a alert (bell, beep when printing)
  - \b backspace
  - \n newline
  - \t horizontal tab
  - \" represents the " char so that it can appear inside a string without ending string prematurely
  - \\ represents the \ char so \ can be a standalone without compiler assuming escape sequence
*/