#include <stdio.h>

int main(void) {
    int n, sum = 0;
    printf("This program sums a series of integers.\nEnter integers (0 to terminate): ");
    scanf("%d", &n); //while loops will generally have extra things in front (usually unavoidable)
    while (n != 0) { //because 0 is the termination condition
        sum += n;
        scanf("%d", &n);
    }
    printf("The sum is: %d\n", sum);
    return 0;
}