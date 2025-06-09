#include <stdio.h>

/*
now with significantly better power function!
looks like fast exponentiation sort of
*/

int power(int x, int n) {
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        return power(x, n / 2) * power(x, n / 2);
    } else {
        return x * power(x, n - 1);
    }
}

/*
hardcoded polynomial
with extra arguments it could be more generalized
also could replace with longs b/c values get big quickly
*/
int poly(int x) {
    return 3 * power(x, 5) + 2 * power(x, 4) - 5 * power(x, 3) - power(x, 2) + 7 * x - 6;
}

int main(void) {
    int x;
    printf("Enter a value for x: ");
    scanf("%d", &x);
    printf("f(x) = %d\n", poly(x));
}