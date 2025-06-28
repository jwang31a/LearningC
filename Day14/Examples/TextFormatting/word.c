#include <stdio.h>
#include "word.h"

int read_char(void) {
    int ch = getchar();
    return (ch == '\n' || ch == '\t') ? ' ' : ch;
}

int read_word(char *word, int len) {
    int ch, pos = 0;
    while ((ch = read_char()) == ' '); //gets rid of leading whitespace
    while (ch != ' ' && ch != EOF) { //while character being read is a char and not the end of the file
        if (pos < len) {
            word[pos++] = ch;
        }
        ch = read_char();
    }
    if (pos > len) {
        word[pos] = '*';
    } else {
        word[pos] = '\0'; //finishes the string with null character
    }
    return pos;
}