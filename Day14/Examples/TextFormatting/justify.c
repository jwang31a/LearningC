/*
formats file of text
*/

#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(void) {
    char word[MAX_WORD_LEN + 2]; //word length + space and a null character?
    int word_len;
    clear_line();
    for (;;) {
        word_len = read_word(word, MAX_WORD_LEN + 1);
        if (word_len == 0) {
            flush_line();
            return 0;
        }
        // if (word_len > MAX_WORD_LEN) { //deals with words greater than 20 characters
        //     word[MAX_WORD_LEN] = '*';
        // }
        if (word_len + 1 > space_remaining()) { //if not enough space, write what's already in the line
            write_line();
            clear_line();
        }
        add_word(word);
    }
}