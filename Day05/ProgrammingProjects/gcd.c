#include <stdio.h>

//slightly more stuff than the textbook wants but it's cool i guess
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
    printGcd(0);
    lowestTerms();
    return 0;
}