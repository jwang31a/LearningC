#include <stdio.h>

/*
fun way of getting squares from using odd numbers
*/

int main(void) {
    int i, n, odd, square;
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);
    i = 1;
    odd = 3;
    for (square = 1; i <=n; odd += 2) {
        printf("%10d%10d\n", i, square);
        ++i;
        square += odd;
    }
    return 0;
}