#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0; //useful for adding a space before words
int add_extra_space = false;

void clear_line(void) {
    line[0] = '\0';
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word) {
    if (num_words > 0) {
        line[line_len] = ' ';
        line[line_len + 1] = '\0';
        line_len++; //temporarily adds a space after the line
    }
    strcat(line, word);
    line_len += strlen(word);
    num_words++;
}

int space_remaining(void) {
    return MAX_LINE_LEN - line_len;
}

void write_line(void) {
    int extra_spaces, spaces_to_insert, i, j;
    extra_spaces = MAX_LINE_LEN - line_len;
    add_extra_space = !add_extra_space;
    for (i = 0; i < line_len; i++) {
        if (line[i] != ' ') { //if we have a word, just putchar
            putchar(line[i]);
        } else {
            spaces_to_insert = extra_spaces / (num_words - 1); //instead of 1 space, put however many spaces are necessary
            if (add_extra_space && extra_spaces > 0) {
                spaces_to_insert++;
                add_extra_space = !add_extra_space;
            }
            for (j = 1; j <= spaces_to_insert + 1; j++) { //guaranteed at least 1 space
                putchar(' ');
            }
            extra_spaces -= spaces_to_insert;
            num_words--;
        }
    }
    putchar('\n'); //ends the line off with a newline
}

void flush_line(void) { //puts the line string
    if (line_len > 0) {
        puts(line);
    }
}