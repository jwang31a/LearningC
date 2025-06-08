#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_DIGITS 10

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
int digits[4][4 * MAX_DIGITS] = {0};

void clear_digits_array(void) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < MAX_DIGITS; j++) {
            digits[i][j] = 0;
        }
    }
}

void process_digit(int digit, int position) {
    for (int i = 0; i < 7; i++) {
        if (segments[digit][i]) {
            digits[position][] = 
        }
    }
}

void print_digits_array(void) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < MAX_DIGITS; j++) {
            printf("%c", segments[i][j]);
        }
    }
}

int main(void) {
    char c;
    int position = 0;
    while ((c = getchar()) != '\n') {
        if (!isdigit(c)) {
            continue;
        }
        process_digit(c - '0', position);
        position += 4;
    }
    return 0;
}