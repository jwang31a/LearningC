#include <stdio.h>

int main(void) {
    //unary plus and minus (one operand)
    int i = +1; //this just emphasizes positivity (doesn't actually do anything)
    int j = -i; //flip sign
    printf("i = %d, j = %d\n", i, j);
    //mix and match ints with floats for math
    printf("%f\n", 2 + 2.5f);
    printf("%f\n", 5 - 1.5f);
    printf("%f\n", 5 * 4.01);
    printf("%f\n", 6 / 2.5);
    //cannot mix floats with ints with % remainder
    printf("%d\n", 100 % 13);
    //for division with negative numbers, truncate towards 0
    printf("%d\n", -9 / 7);
    //for modulo of negative numbers, take sign of i
    printf("%d\n", -9 % 7);
    printf("%d\n", 9 % -7);
    return 0;
}

/*
follows basic order of operations:
unary  + - (high)
binary * / %
       + - (low)
left associative operations group left to right (binary arithmetic operators)
right associative operations group right to left (unary)
*/