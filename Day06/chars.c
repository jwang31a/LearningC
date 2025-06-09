#include <stdio.h>
#include <limits.h>

char convertUpper(char ch) { //simple conversion function that converts lower case to upper
    if ('a' <= ch && ch <= 'z') {
        ch = ch - 'a' + 'A';
    }
    return ch;
}

int main(void) {
    printf("converted: %c\n", convertUpper('a'));
    printf("converted: %c\n", convertUpper('N'));
    printf("char min: %d\n", CHAR_MIN);
    char ch;
    while ((ch = getchar()) == ' '); //skips indefinite number of blank characters
    //very useful phrase
    return 0;
}

/*
ASCII 7 bit code representing 128 characters
  - extension to 8 bit called Latin 1\
chars enclosed in single quotes
C treats chars as small integers
  - characters have integer values from 0 to 127
  - 'a' has value 97, 'A' has value 65, '0' has value 48, ' ' value 32
  - character constants have int type actually (doesn't matter for us)
  - characters can be compared
  - character math can lead to unexpected results as well
chars can be signed as well
  - looks like gcc chars are signed

arithmetic types:
  - integer types:
      - char
      - signed integer types (standard and extended)
      - unsigned integer types (standard and extended)
      - enumerated types
  - floating types:
      - real floating types
      - complex types

escape sequences:
  - character escapes
  - numeric escapes
character escapes:
  - alert (bell) \a
  - backspace \b
  - form feed \f
  - newline \n
  - carriage return \r
  - horizontal tab \t
  - vertical tab \v
  - backslash \\
  - question mark \? (rare)
  - single quote \' (allows char to contain ' char)
  - double quote \" (allows string to contain " char)
numeric escapes help with all the nonprinting ascii characters plus extra characters
  - using octal:
      - octal number with at most 3 digits (max usually 377 octal)
      - doesn't have to start with 0
  - with hexadecimal:
      - \x followed be hexadecimal number (x must be lowercase)
      - likely can't exceed ff if 8 bit characters
  - when used as character constant, escape sequence enclosed in single quotes
  - good idea to define macro
also trigraph sequences for #, [, \, ], ^, {, |, }, ~ (may not be available on some keyboards)
toupper(char) from <ctype.h> directive
%c conversion specification for single characters
  - does not skip white space before reading character
  - because ' ' is its own character
  - " %c" skips white space then next character
putchar(ch) and ch = getchar()
  - getchar() actually returns int
  - simpler than scanf or printf, which are designed for many things
*/