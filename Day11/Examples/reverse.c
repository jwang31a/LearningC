#include <stdio.h>

#define N 10

int main(void) {
    int a[N], *p;
    printf("Enter %d numbers: ", N);
    for (p = a; p < a + N; p++) {
        scanf("%d", p);
    } //because p is already a pointer we don't need to get the address
    printf("In reverse order:");
    for (p = a + N - 1; p >= a; p--) {
        printf(" %d", *p);
    } //p stores the address, so *p gets the thing that p points to in the array
    printf("\n");
    return 0;
}