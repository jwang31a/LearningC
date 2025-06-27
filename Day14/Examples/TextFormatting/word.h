#ifndef WORD_H
#define WORD_H

/*
reads next word from input and stores in word
empty word if end of file
truncates word if length exceeds len
*/
int read_word(char *word, int len);

#endif

/*
this is protected, even though it technically doesn't need to be
always good practice to protect header files like this
*/