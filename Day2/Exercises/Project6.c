/*
modified addfrac.c
*/

#include <stdio.h>

int main(void) {
    int num1, denom1, num2, denom2;
    printf("Enter two fractions separated by a plus sign: ");
    scanf("%d/%d+%d/%d", &num1, &denom1, &num2, &denom2);
    int newNum = num1 * denom2 + num2 * denom1;
    int newDenom = denom1 * denom2;
    printf("The sum is %d/%d\n", newNum, newDenom);
    return 0;
}