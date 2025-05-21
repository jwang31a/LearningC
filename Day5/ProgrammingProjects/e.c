#include <stdio.h>

/*
it seems that beyond 30, the value of e becomes inf?
*/

int main(void) {
    int n;
    long factorial = 1;
    float e;
    printf("Enter n, where n is the number of fractions of the infinite series used to calculate e: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        e += 1.0f / factorial;
        factorial *= i;
    }
    printf("e calculated using %d fractions: %f\n", n, e);
    return 0;
}