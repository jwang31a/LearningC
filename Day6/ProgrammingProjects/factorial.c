#include <stdio.h>

/*
short supports max of 7!, 8! overflows
int max 12!, 13! overflows
long max 20!, 21! overflows
i would do this for the floating point types but it's getting tedious, you get the point by now
*/

short factorialShort(int n) {
    short fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int factorialInt(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

long factorialLong(int n) {
    long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main(void) {
    short factShort, shortN;
    int factInt, intN;
    long factLong, longN;
    float factFloat, floatN;
    double factDouble, doubleN;
    long double factLDouble, ldN;
    printf("short n = ");
    scanf("%hd", &shortN);
    factShort = factorialShort(shortN);
    printf("Short factorial: %hd\n", factShort);

    printf("int n = ");
    scanf("%d", &intN);
    factInt = factorialInt(intN);
    printf("Int factorial: %d\n", factInt);

    printf("long n = ");
    scanf("%ld", &longN);
    factLong = factorialLong(longN);
    printf("Long factorial: %ld\n", factLong);
    
    // printf("long n = ");
    // scanf("%ld", &longN);
    // factLong = factorial(longN);
    
    // printf("float n = ");
    // scanf("%f", &floatN);
    // factFloat = factorial(floatN);
    return 0;
}