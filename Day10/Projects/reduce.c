#include <stdio.h>

int getGcd(int m, int n) {
    while (n != 0) {
        int rem = m % n;
        m = n;
        n = rem;
    }
    if (m < 0) {
        m = -m;
    }
    return m;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator) {
    int gcd = getGcd(numerator, denominator);
    *reduced_numerator = numerator / gcd;
    *reduced_denominator = denominator / gcd;
}

int main(void) {
    int num, den, red_num, red_den;
    printf("Enter a fraction: ");
    scanf("%d/%d", &num, &den);
    reduce(num, den, &red_num, &red_den);
    printf("In lowest terms: %d/%d\n", red_num, red_den);
    return 0;
}