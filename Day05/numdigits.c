#include <stdio.h>

/*
edited so that the integer given can be positive or negative
*/

int main(void) {
    int n, i;
    printf("Enter an integer: ");
    scanf("%d", &n);
    do { //do while is necessary here because integers have a minimum of 1 digit, while loop for input of 0 would lead to 0 digits
        n /= 10;
        ++i;
    } while (n != 0);
    printf("The number has %d digit(s).\n", i);
    return 0;
}