#include <stdio.h>

int main(void) {
    long ean;
    int sum1, sum2, rem, check;
    printf("Enter the first 12 digits of a EAN: ");
    scanf("%12ld", &ean);
    sum1 = (ean % 10) + ((ean / 100l) % 10) + ((ean / 10000l) % 10) + ((ean / 1000000l) % 10) + ((ean / 100000000l) % 10) + ((ean / 10000000000l) % 10);
    sum2 = ((ean / 10l) % 10) + ((ean / 1000l) % 10) + ((ean / 100000l) % 10) + ((ean / 10000000l) % 10) + ((ean / 1000000000l) % 10) + ((ean / 100000000000l) % 10);
    sum2 += (3 * sum1);
    --sum2;
    rem = sum2 % 10;
    check = 9 - rem;
    printf("Check digit: %d\n", check);
}