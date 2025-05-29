#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define DIRS 4 //0 up, 1 right, 2 down, 3 left, -1 (or any number not 0-3) means no direction chosen yet
#define DIM 10 //10 by 10 matrix

/*
welcome to conditional megalopolis
holy crap this looks terrible
*/

int printMatrix(char matrix[][DIM]) {
    printf("===============\n");
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            if (matrix[i][j] >= 'A' && matrix[i][j] <= 'Z') {
                printf("%c ", matrix[i][j]);
            } else {
                printf("%c ", '.');
            }
        }
        printf("\n");
    }
}

int main(void) {
    srand((unsigned) time(NULL));
    int i = 0, j = 0;
    char c = 'A';
    char matrix[DIM][DIM] = {c};
    while (c < 'Z') {
        if ((i - 1 < 0  || (matrix[i - 1][j] >= 'A' && matrix[i - 1][j] <= 'Z'))
            && (j + 1 >= DIM || (matrix[i][j + 1] >= 'A' && matrix[i][j + 1] <= 'Z'))
            && (i + 1 >= DIM || (matrix[i + 1][j] >= 'A' && matrix[i + 1][j] <= 'Z'))
            && (j - 1 < 0 || (matrix[i][j - 1] >= 'A' && matrix[i][j - 1] <= 'Z')))
                break;
        int dir = -1;
        while (dir == -1) {
            dir = rand() % DIRS;
            switch (dir) {
                case 0:
                    if (i - 1 < 0 || (matrix[i - 1][j] >= 'A' && matrix[i - 1][j] <= 'Z')) {
                        dir = -1;
                    } else {
                        i--;
                    }
                    break;
                case 1:
                    if (j + 1 >= DIM || (matrix[i][j + 1] >= 'A' && matrix[i][j + 1] <= 'Z')) {
                        dir = -1;
                    } else {
                        j++;
                    }
                    break;
                case 2:
                    if (i + 1 >= DIM || (matrix[i + 1][j] >= 'A' && matrix[i + 1][j] <= 'Z')) {
                        dir = -1;
                    } else {
                        i++;
                    }
                    break;
                case 3:
                    if (j - 1 < 0 || (matrix[i][j - 1] >= 'A' && matrix[i][j - 1] <= 'Z')) {
                        dir = -1;
                    } else {
                        j--;
                    }
                    break;
            }
        }
        matrix[i][j] = ++c;
        printMatrix(matrix);
    }
    return 0;
}