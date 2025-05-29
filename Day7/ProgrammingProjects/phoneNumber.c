#include <stdio.h>
#include <ctype.h> //deals with characters

#define MAX_LENGTH 15

/*
2=abc
3=def
4=ghi
5=jkl
6=mno
7=p(q)rs
8=tuv
9=wxy(z)

now using arrays!
*/

int main(void) {
    printf("Enter phone number: ");
    int i = 0;
    char phone[MAX_LENGTH] = {0};
    char c;
    while ((c = tolower(getchar())) != '\n') {
        switch (c) {
            case 'a': case 'b': case 'c':
                phone[i++] = '2';
                break;
            case 'd': case 'e': case 'f':
                phone[i++] = '3';
                break;
            case 'g': case 'h': case 'i':
                phone[i++] = '4';
                break;
            case 'j': case 'k': case 'l':
                phone[i++] = '5';
                break;
            case 'm': case 'n': case 'o':
                phone[i++] = '6';
                break;
            case 'p': case 'q': case 'r': case 's':
                phone[i++] = '7';
                break;
            case 't': case 'u': case 'v':
                phone[i++] = '8';
                break;
            case 'w': case 'x': case 'y': case 'z':
                phone[i++] = '9';
                break;
            default:
                phone[i++] = c;
                break;
        }
    }
    i = 0;
    while (i < MAX_LENGTH && phone[i] != 0) {
        printf("%c", phone[i++]);
    }
    printf("\n");
    return 0;
}