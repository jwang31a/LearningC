#include <stdio.h>

/*
for large values of i, weird things start happening
short's max seems to be 32767 (16 bit signed, 2^15 - 1)
int's max seems to be 2147483647
also includes enter press after every 24 squares
*/

int main(void) {
    short i, n;
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%hd", &n);
    for (i = 1; i <= n; i++) {
        if ((i - 1) % 24 == 0) {
            printf("Press Enter to continue... ");
            while (getchar() != '\n');
        }
        printf("%10hd%10d\n", i, (int) i * i);
    }
    return 0;
}