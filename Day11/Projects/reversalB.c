#include <stdio.h>

#define N 100

/*
this some real sketchy pointer arithmetic
hoping this doesn't change things outside the program
*/

int main(void) {
    char c;
    char message[N] = {0};
    char *p = message;
    printf("Enter a message: ");
    while ((c = getchar()) != '\n') {
        if (p >= message + 100) {
            printf("Character limit exceeded.\n");
            break;
        }
        *p++ = c;
    }
    printf("Reversal is: ");
    for (char *j = p - 1; j >= message; j--) {
        printf("%c", *j);
    }
    printf("\n");
    return 0;
}