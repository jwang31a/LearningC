#include <stdio.h>

/*
modified for double input
probably scuffed in some way that i can't see
*/

int main(void) {
    double n, sum = 0;
    printf("This program sums a series of integers.\n");
    printf("Enter integers (0 to terminate): ");
    scanf("%lf", &n);
    while (n != 0) {
        sum += n;
        scanf("%lf", &n);
    }
    printf("The sum is: %lf\n", sum);
    return 0;
}