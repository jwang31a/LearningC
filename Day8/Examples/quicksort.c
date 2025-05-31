#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

/*
their quicksort algorithm is suboptimal so i decided to use the CS 1332 version (which could be better as well)
also im braindead do not let me write important secure code because i will not be able to do it
*/

void quicksort(int a[], int n);
void quicksortHelper(int a[], int low, int high);
void swap(int a[], int i, int j);
void printArray(int a[]);

int main(void) {
    int a[N]; //technically we could declare int i here but that feels wrong somehow
    printf("Enter %d numbers to be sorted: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    quicksort(a, N);
    printf("In sorted order: ");
    // quicksortHelper(a, 0, N - 1);
    printArray(a);
    return 0;
}

void printArray(int a[]) {
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void quicksort(int a[], int n) {
    srand((unsigned) time(NULL));
    quicksortHelper(a, 0, n - 1);
}

void quicksortHelper(int a[], int low, int high) {
    if (high - low <= 0) {
        return;
    }
    int pivotIndex = rand() % (high + 1 - low) + low;
    int pivotData = a[pivotIndex];
    printf("low = %d, mid = %d, high = %d\n", low, pivotIndex, high);
    swap(a, pivotIndex, low);
    int i = low + 1;
    int j = high;
    while (i <= j) {
        while (i <= j && a[i] <= pivotData) {
            i++;
        }
        while (i <= j && a[j] >= pivotData) {
            j--;
        }
        if (i <= j) {
            swap(a, i, j);
            i++;
            j--;
        }
        printf("i = %d, j = %d\n", i, j);
        printArray(a);
    }
    swap(a, low, j);
    printArray(a);
    quicksortHelper(a, low, j - 1);
    quicksortHelper(a, j + 1, high);
}

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}