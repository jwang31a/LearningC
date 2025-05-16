#include <stdio.h>

/*
I decided to not completely follow the textbook for this file b/c having 5 variables for 1 group
when 1 would suffice seems wasteful. Plus, this is the section where we talk about modulo, so might as well use it.
*/

int main(void) {
    int first, group1, group2, check;
    printf("Enter the first (single) digit: ");
    scanf("%d", &first);
    printf("Enter the first group of five digits: ");
    scanf("%d", &group1);
    printf("Enter the second group of five digits: ");
    scanf("%d", &group2);
    int sum1 = first + ((group1 / 1000) % 10) + ((group1 / 10) % 10) + ((group2 / 10000) % 10) + ((group2 / 100) % 10) + ((group2 / 1) % 10);
    int sum2 = ((group1 / 10000) % 10) + ((group1 / 100) % 10) + (group1 % 10) + ((group2 / 1000) % 10) + ((group2 / 10) % 10);
    int total = 3 * sum1 + sum2;
    total -= 1;
    int rem = total % 10;
    check = 9 - rem;
    printf("Check digit: %d\n", check);
    return 0;
}