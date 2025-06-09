#include <stdio.h>
#include <math.h> //for fabs (floating point absolute value)

/*
newton's method for approximating square roots
sort of like a binary search
x is user inputted number that we want to find the square root of
y is initially a guess, i.e. 1
x/y computed, then average of y and x/y
average then becomes y, with new calculations at each step
*/

int main(void) {
    double x, y = 1, quotient, avg;
    printf("Enter a positive number: ");
    scanf("%lf", &x);
    quotient = x / y;
    avg = (y + quotient) / 2;
    while (fabs(avg - y) >= 0.00001 * y) {
        y = avg;
        quotient = x / y;
        avg = (y + quotient) / 2;
    }
    printf("Square root: %.5lf\n", avg);
    return 0;
}