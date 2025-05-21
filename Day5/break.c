#include <stdio.h>

void printIsPrime(void) {
    int n, d;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n == 1) {
        printf("%d is neither prime nor composite\n", n);
        return;
    } else if (n < 1) {
        printf("non-positive numbers cannot be prime!\n");
        return;
    }
    for (d = 2; d < n; d++) { //i'm pretty sure the end condition can be n / 2 actually
        if (n % d == 0) {
            break;
        }
    }
    if (d < n) {
        printf("%d is divisible by %d\n", n, d);
    } else {
        printf("%d is prime\n", n);
    }
}

void breakTest() {
    int i = 0;
    while (i < 10) {
        switch (i % 2) {
            case 0: printf("%d is even\n", i);
                break;
            case 1: printf("%d is odd\n", i);
                break;
        }
        i++;
    }
}

int main(void) {
    printIsPrime();
    printf("=====break test=====\n");
    breakTest();
    return 0;
}

/*
break only exits out of innermost nesting
*/