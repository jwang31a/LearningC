#include <stdio.h>

/*
apparently with ints this is supposed to overflow for their example, but that doesn't happen
probably because ints in gcc are 32 bit not 16 bit
but for the sake of this example everything is a long despite it not being necessary
*/

int main(void) {
    long n, sum = 0;
    printf("This program sums a series of integers.\n");
    printf("Enter integers (0 to terminate): ");
    scanf("%ld", &n);
    while (n != 0) {
        sum += n;
        scanf("%ld", &n);
    }
    printf("The sum is: %ld\n", sum);
    return 0;
}