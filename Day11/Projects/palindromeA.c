#include <stdio.h>
#include <ctype.h>

#define N 100

/*
mess of variables yippee
*/

int main(void) {
    char message[N], c;
    int i = 0;
    printf("Enter a message: ");
    while ((c = getchar()) != '\n') {
        if (isalpha(c)) {
            message[i++] = tolower(c);
        }
    }
    for (int j = i - 1, k = 0; j >= k; j--) {
        if (message[j] != message[k++]) {
            printf("Not a palindrome\n");
            return 0;
        }
    }
    printf("Palindrome\n");
    return 0;
}