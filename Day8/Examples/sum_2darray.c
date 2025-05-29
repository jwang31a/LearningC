#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10

int sum_two_dimensional_array(int a[][LEN], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < LEN; j++) {
            sum += a[i][j];
        }
    }
    return sum;
}

//not actually in the example but it's cool
void rand_array(int a[][LEN], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < LEN; j++) {
            a[i][j] = rand() % 10;
        }
    }
}

int main(void) {
    srand((unsigned) time(NULL));
    int n = 10;
    int a[n][LEN];
    rand_array(a, n);
    printf("%d\n", sum_two_dimensional_array(a, n));
}