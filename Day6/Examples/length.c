#include <stdio.h>

/*
short program that uses the getchar inside while loop to shorten loop
*/

int main(void) {
    char ch;
    int len = 0;
    printf("Enter a message: ");
    while (getchar() != '\n') {
        len++;
    }
    printf("Your message was %d character(s) long.\n", len);
    return 0;
}