#include <stdio.h>

#define DIM 5

/*
screw efficiency and all the principles of coding i know
i just want to get this done
this hurts to say and do
too many loops augh

alright the loops have been unlooped thankfully

small modification so that this is in the context of student scores
*/

int main(void) {
    int matrix[DIM][DIM] = {0};
    int rows[DIM] = {0};
    int cols[DIM] = {0};
    for (int i = 0; i < DIM; i++) {
        printf("Enter student %d scores: ", i + 1);
        for (int j = 0; j < DIM; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Student averages:");
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            rows[i] += matrix[i][j];
        }
        printf(" %.2f", (float) rows[i] / DIM);
    }
    printf("\nQuiz averages:");
    for (int j = 0; j < DIM; j++) {
        for (int i = 0; i < DIM; i++) {
            cols[j] += matrix[i][j];
        }
        printf(" %.2f", (float) cols[j] / DIM);
    }
    printf("\n");
}