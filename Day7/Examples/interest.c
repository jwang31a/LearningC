#include <stdio.h>
#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00

int main(void) {
    int rate, year, num_years;
    double value[5];
    printf("Enter interest rate: ");
    scanf("%d", &rate);
    printf("Enter number of years: ");
    scanf("%d", &num_years);
    printf("\nYears");
    for (int i = 0; i < NUM_RATES; i++) {
        printf("%6d%%", rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");
    for (int year = 1; year <= num_years; year++) {
        printf("%3d    ", year);
        for (int j = 0; j < NUM_RATES; j++) {
            value[j] += (rate + j) / 100.0 * value[j];
            printf("%7.2f", value[j]);
        }
        printf("\n");
    }
    return 0;
}