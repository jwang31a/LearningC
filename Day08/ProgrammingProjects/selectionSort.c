#include <stdio.h>

#define N 10

/*
and to think i wanted to be a data structures and algorithms TA
1 month after the semester ended and it's joever for me 💀
*/

void printArray(int a[]) {
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void selectionSort(int a[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int max = i;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[max]) {
                max = j;
            }
        }
        swap(a, i, max);
    }
}

int main(void) {
    int a[N];
    printf("Enter %d numbers to be sorted: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    selectionSort(a, N);
    printf("In sorted order: ");
    printArray(a);
    return 0;
}