#include <stdio.h>

/*
there are two labels here: loopdone and end
  - loopdone is equivalent to breaking out of the loop
  - end is equivalent to returning early
very rarely used in modern languages, but it's cool
*/
void printIsPrimeGoto(void) { //side note: for functions with no argument, explicit void may be best practice in C to avoid passing unintended variables
    int n, d;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n == 1) {
        printf("%d is neither prime nor composite\n", n);
        goto end;
    } else if (n < 1) {
        printf("non-positive numbers cannot be prime!\n");
        goto end;
    }
    for (d = 2; d < n; d++) { //i'm pretty sure the end condition can be n / 2 actually
        if (n % d == 0) {
            goto loopdone;
        }
    }
    loopdone:
    if (d < n) {
        printf("%d is divisible by %d\n", n, d);
    } else {
        printf("%d is prime\n", n);
    }
    end:
}

/*
this allows complete early exits
also helps with exiting nested loops
*/

void breakTest() {
    int i = 0;
    while (i < 50) {
        switch (i % 23) {
            case 22: printf("early exit\n");
                goto loopdone;
            default: printf("%d does not allow early exit\n", i);
                break;
        }
        i++;
    }
    loopdone:
}

int main(void) {
    printIsPrimeGoto();
    breakTest();
    return 0;
}

/*
goto statement can jump to any statement in a function
  - statement needs a label
  - C99 restricts goto from bypassing declaration of variable length array
  - label is identifier placed at beginning of statement
      - denoted identifier : statement
      - statement may have more than 1 label
  - goto identifier;
  - label L must be in same function as goto statement
*/