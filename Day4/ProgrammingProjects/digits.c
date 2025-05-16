#include <stdio.h>
#include <stdbool.h>

/*
this is definitely not how i would compute the number of digits,
but the textbook specifies that i should use if statements
it is what it is
*/

int main(void) {
    int n, digits;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (0 <= n && n <= 9) digits = 1;
    else if (n <= 99) digits = 2;
    else if (n <= 999) digits = 3;
    else if (n <= 9999) digits = 4;
    printf("The number %d has %d digits\n", n, digits);
    return 0;
}