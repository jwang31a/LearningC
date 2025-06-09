#include <stdio.h>

//only change is the empty for loop body and an extra condition
void printIsPrimeNull(void) {
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
    for (d = 2; d < n && n % d != 0; d++); //null statement on same line now
    if (d < n) {
        printf("%d is divisible by %d\n", n, d);
    } else {
        printf("%d is prime\n", n);
    }
}

int main(void) {
    printIsPrimeNull();
    return 0;
}

/*
statements can be null (only semicolon)
good for writing loops with empty bodies

be careful with null statements:
semicolons will end loops and control flow early
  - for control flow, no matter what the controlling expression value is, same value every time
*/