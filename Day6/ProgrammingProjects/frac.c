#include <stdio.h>

/*
now with add, subtract, multiply, divide functionality!
looks like it works yippee
we don't know about arrays yet so even though i want to add functionality of multiple functions per expression,
textbook hasn't covered it yet
*/

int printGcd(_Bool print) {
    int m, n;
    printf("Enter two integers: ");
    scanf("%d%d", &m, &n);
    while (n != 0) {
        int rem = m % n;
        m = n;
        n = rem;
    }
    if (print)
        printf("Greatest common divisor: %d\n", m);
    return m;
}

int getGcd(int m, int n) {
    while (n != 0) {
        int rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}

void lowestTerms(void) {
    int n, d, gcd;
    printf("Enter a fraction: ");
    scanf("%d/%d", &n, &d);
    gcd = getGcd(n, d); //looks like compiler doesn't like variables and function having same name
    printf("In lowest terms: %d/%d\n", n / gcd, d / gcd);
}

int main(void) {
    int n1, n2, d1, d2, n, d, gcd;
    char operation;
    printf("Enter an expression with two fractions (with spaces between operation and fractions): ");
    scanf("%d/%d %c %d/%d", &n1, &d1, &operation, &n2, &d2);
    switch (operation) {
        case '+':
            n = n1 * d2 + n2 * d1;
            d = d1 * d2;
            break;
        case '-':
            n = n1 * d2 - n2 * d1;
            d = d1 * d2;
            break;
        case '*':
            n = n1 * n2;
            d = d1 * d2;
            break;
        case '/':
            n = n1 * d2;
            d = d1 * n2;
            break;
    }
    gcd = getGcd(n, d);
    n /= gcd;
    d /= gcd;
    if (d < 0) {
        n *= -1;
        d *= -1;
    }
    printf("The result is %d/%d.\n", n, d);
    return 0;
}