#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define DIRS 4 //0 up, 1 right, 2 down, 3 left, -1 (or any number not 0-3) means no direction chosen yet
#define DIM 10 //10 by 10 matrix

/*
this uses a whole lot more functions and stuff from the C library than the textbook probably intends
mostly for organization and code simplification though
main function body has mostly been moved out
*/

/*
oops i already did this before i learned about functions
im too good
*/
int printMatrix(int n, char matrix[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] >= 'A' && matrix[i][j] <= 'Z') {
                printf("%c ", matrix[i][j]);
            } else {
                printf("%c ", '.');
            }
        }
        printf("\n");
    }
}

void init_matrix(int n, char matrix[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = '.';
        }
    }
}

void generate_random_walk(int n, char matrix[][n]) {
    srand((unsigned) time(NULL));
    int i = 0, j = 0;
    char c = 'A';
    init_matrix(n, matrix);
    matrix[i][j] = c;
    while (c < 'Z') {
        bool up = 0, down = 0, left = 0, right = 0;
        int dir;
        if (i - 1 >= 0 && !isalpha(matrix[i - 1][j])) {
            up = true;
        }
        if (j + 1 < DIM && !isalpha(matrix[i][j + 1])) {
            right = true;
        }
        if (i + 1 < DIM && !isalpha(matrix[i + 1][j])) {
            down = true;
        }
        if (j - 1 >= 0 && !isalpha(matrix[i][j - 1])) {
            left = true;
        }
        if (!(up || right || down || left)) {
            break;
        }
        dir = rand() % DIRS;
        switch (dir) {
            case 0:
                if (up) {
                    matrix[--i][j] = ++c;
                }
                break;
            case 1:
                if (right) {
                    matrix[i][++j] = ++c;
                }
                break;
            case 2:
                if (down) {
                    matrix[++i][j] = ++c;
                }
                break;
            case 3:
                if (left) {
                    matrix[i][--j] = ++c;
                }
                break;
        }
    }
}

int main(void) {
    char matrix[DIM][DIM];
    generate_random_walk(DIM, matrix);
    printMatrix(DIM, matrix);
    return 0;
}