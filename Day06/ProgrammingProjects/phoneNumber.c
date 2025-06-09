#include <stdio.h>
#include <ctype.h> //deals with characters

/*
2=abc
3=def
4=ghi
5=jkl
6=mno
7=p(q)rs
8=tuv
9=wxy(z)

don't print chars, only print strings (string literals)
when converting, remember that chars can also be upper case
*/

int main(void) {
    printf("Enter phone number: ");
    char c = tolower(getchar());
    while (c != '\n') {
        switch (c) {
            case 'a': case 'b': case 'c':
                printf("2");
                break;
            case 'd': case 'e': case 'f':
                printf("3");
                break;
            case 'g': case 'h': case 'i':
                printf("4");
                break;
            case 'j': case 'k': case 'l':
                printf("5");
                break;
            case 'm': case 'n': case 'o':
                printf("6");
                break;
            case 'p': case 'q': case 'r': case 's':
                printf("7");
                break;
            case 't': case 'u': case 'v':
                printf("8");
                break;
            case 'w': case 'x': case 'y': case 'z':
                printf("9");
                break;
            default:
                printf("%c", c);
                break;
        }
        c = tolower(getchar());
    }
    printf("\n");
    return 0;
}