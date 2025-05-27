#include <stdio.h>
#define N 10 //macros are nice when working with arrays

/*
doesn't actually reverse the order of elements in array
instead loops backward
*/

int main(void) {
    int a[10];
    printf("Enter 10 numbers: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    printf("In reverse order:");
    for (int i = N - 1; i >= 0; i--) {
        printf(" %d", a[i]);
    }
    printf("\n");
    return 0;
}