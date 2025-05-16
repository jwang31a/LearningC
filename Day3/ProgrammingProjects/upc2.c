#include <stdio.h>

/*
rewritten so only one block of numbers as input;
*/

int main(void) {
    long upc;
    printf("Enter the first 11 digits of a UPC: ");
    scanf("%11ld", &upc);
    int sum1 = ((upc / 1) % 10) + ((upc / 100) % 10) + ((upc / 10000) % 10) + ((upc / 1000000) % 10) + ((upc / 100000000) % 10) + ((upc / 10000000000) % 10);
    int sum2 = ((upc / 10) % 10) + ((upc / 1000) % 10) + ((upc / 100000) % 10) + ((upc / 10000000) % 10) + ((upc / 1000000000) % 10);
    int total = 3 * sum1 + sum2;
    total -= 1;
    int rem = total % 10;
    int check = 9 - rem;
    printf("Check digit: %d\n", check);
    return 0;
}