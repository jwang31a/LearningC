#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_DIGITS 10

/*
remember that while max digits is 10, the actual length of what we're printing and storing is 40 chars long
*/

//segment representation using bools
bool segments[10][7] = {
    {true, true, true, true, true, true, false},
    {false, true, true, false, false, false, false},
    {true, true, false, true, true, false, true},
    {true, true, true, true, false, false, true},
    {false, true, true, false, false, true, true},
    {true, false, true, true, false, true, true},
    {true, false, true, true, true, true, true},
    {true, true, true, false, false, false, false},
    {true, true, true, true, true, true, true},
    {true, true, true, true, false, true, true},
};
//storage of display
int digits[4][4 * MAX_DIGITS] = {0};
//grid that stores x and y coordinates based on the segment
int grid[7][2] = {
    {0, 1},
    {1, 2},
    {2, 2},
    {2, 1},
    {2, 0},
    {1, 0},
    {1, 1},
};

void print_digits_array(void);

void clear_digits_array(void) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 * MAX_DIGITS; j++) {
            digits[i][j] = ' ';
        }
    }
}

void process_digit(int digit, int position) {
    for (int i = 0; i < 7; i++) {
        if (segments[digit][i]) {
            int row = grid[i][0];
            int col = grid[i][1] + position;
            digits[row][col] = i % 3 == 0 ? '_' : '|';            
        }
    }
}

void print_digits_array(void) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 * MAX_DIGITS; j++) {
            putchar(digits[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    char c;
    int position = 0;
    clear_digits_array();
    printf("Enter a number: ");
    while ((c = getchar()) != '\n') {
        if (isdigit(c)) {
            process_digit(c - '0', position);
            position += 4;
        }
    }
    print_digits_array();
    return 0;
}