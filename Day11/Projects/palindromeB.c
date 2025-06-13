#include <stdio.h>
#include <ctype.h>

#define N 100

/*
okay i'm getting the hang of pointers gradually
it's kinda cool to use
*/

int main(void) {
    char message[N], c, *p = message;
    printf("Enter a message: ");
    while ((c = getchar()) != '\n') {
        if (isalpha(c)) {
            *p++ = tolower(c);
        }
    }
    for (char *j = p - 1, *k = message; j >= k; j--) {
        if (*j != *k++) {
            printf("Not a palindrome\n");
            return 0;
        }
    }
    printf("Palindrome\n");
    return 0;
}