#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define DIRS 4 //0 up, 1 right, 2 down, 3 left, -1 (or any number not 0-3) means no direction chosen yet
#define DIM 10 //10 by 10 matrix

/*
this is a lot better and cleaner, uses bools and better design choices
although the pseudorandom nature based on time means the random walk isn't as truly random as it could be
if i run the program too quickly one after another, it may generate the same random walk
it also looks like a specific direction is preferred over another sometimes, probably due to time and pseudorandomness
*/

int printMatrix(char matrix[][DIM]) {
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
        bool up = 0, down = 0, left = 0, right = 0;
        int dir;
        if (i - 1 >= 0 && matrix[i - 1][j] == 0) {
            up = true;
        }
        if (j + 1 < DIM && matrix[i][j + 1] == 0) {
            right = true;
        }
        if (i + 1 < DIM && matrix[i + 1][j] == 0) {
            down = true;
        }
        if (j - 1 >= 0 && matrix[i][j - 1] == 0) {
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
    printMatrix(matrix);
    return 0;
}