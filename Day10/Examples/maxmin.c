#include <stdio.h>

/*
sort of returns 2 values, but without returning at all
*/
void max_min(int a[], int n, int *max, int *min) {
    *max = *min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > *max) {
            *max = a[i];
        }
        if (a[i] < *min) {
            *min = a[i];
        }
    }
}

int main(void) {
    int a[10], big, small;
    printf("Enter 10 numbers: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    max_min(a, 10, &big, &small);
    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);
    return 0;
}