#include <stdio.h>

/*
putting average after the main function causes problems
probably because the average function is unknown to the main function
*/

double average(double a, double b) {
    return (a + b) / 2;
}

int main(void) {
    double x, y, z;
    printf("Enter three numbers: ");
    scanf("%lf%lf%lf", &x, &y, &z);
    printf("Average of %g and %g: %g\n", x, y, average(x, y));
    printf("Average of %g and %g: %g\n", y, z, average(y, z));
    printf("Average of %g and %g: %g\n", x, z, average(x, z));
}