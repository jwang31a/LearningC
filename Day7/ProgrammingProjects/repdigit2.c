#include <stdio.h>
#include <stdbool.h> //only in C99, but it makes things easier, otherwise define

#define digitSize ((int)(sizeof(digit_seen) / sizeof(digit_seen[0]))) // size definition b/c this is used a lot

/*
slight modification to display repeated digits in a table
extra modification for many values
*/

int main(void) {
    long n;
    printf("Enter a series of numbers (to end input 0): ");
    scanf("%ld", &n);
    while (n != 0) {
        int digit_seen[10] = {0};
        int digit;
        bool repeated = false;
        long copy = n;
        while (copy > 0) {
            digit = copy % 10;
            if (digit_seen[digit]) {
                repeated = true;
            }
            digit_seen[digit]++;
            copy /= 10;
        }
        printf("For %ld:\n", n);
        printf("Digit:      ");
        for (int i = 0; i < digitSize; i++) {
            printf("%3d", i);
        }
        printf("\nOccurrences:");
        for (int i = 0; i < digitSize; i++) {
            printf("%3d", digit_seen[i]);
        }
        printf("\n");
        scanf("%ld", &n);
    }
    return 0;
}