#include <stdio.h>

int main(void) {
    float max = -1.0f;
    printf("Enter numbers one by one. To exit, enter 0 or a negative number.\n");
    for (;;) {
        float n;
        printf("Enter a number: ");
        scanf("%f", &n);
        if (n <= 0.0f) {
            break;
        }
        if (n > max) {
            max = n;
        }
    }
    if (max == -1) {
        printf("You didn't enter a positive number!\n");
    } else {
        printf("The largest number entered was %f\n", max);
    }
    return 0;
}