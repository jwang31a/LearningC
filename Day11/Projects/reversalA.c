#include <stdio.h>

#define N 100

int main(void) {
    char c;
    char message[N] = {0};
    int i = 0;
    printf("Enter a message: ");
    while ((c = getchar()) != '\n') {
        if (i >= 100) {
            printf("Character limit exceeded.\n");
            break;
        }
        message[i++] = c;
    }
    printf("Reversal is: ");
    for (int j = i - 1; j >=0; j--) {
        printf("%c", message[j]);
    }
    printf("\n");
    return 0;
}