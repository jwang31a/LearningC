#ifndef LINE_H
#define LINE_H

/*
clears current line
*/
void clear_line(void);

/*
adds a word to end of current line
if not the first word, then put one space before word
*/
void add_word(const char *word);

/*
returns number of chars left in current line
*/
int space_remaining(void);

/*
writes line with justification
*/
void write_line(void);

/*
writes current line without justification
does nothing if empty line
*/
void flush_line(void);

#endif