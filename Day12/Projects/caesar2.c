#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MESSAGE_LENGTH 80

/*
caesar cipher encryption, now using pointer arithmetic!
also using string.h for cool stuff
*/

void encrypt(char *message, int shift) {
    puts(message);
    for (char *c = message; c < message + strlen(message); c++) {
        if (*c >= 'A' && *c <= 'Z') {
            *c = ((*c - 'A') + shift) % 26 + 'A';
        } else if (*c >= 'a' && *c <= 'z') {
            *c = ((*c - 'a') + shift) % 26 + 'a';
        }
    }
}

int main(void) {
    char message[MESSAGE_LENGTH + 1], c;
    int i = 0;
    int shift;
    printf("Enter message to be encrypted: ");
    while ((c = getchar()) != '\n' && i < MESSAGE_LENGTH) {
        message[i++] = c; 
    }
    message[i] = '\0';
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);
    encrypt(message, shift);
    puts(message);
    return 0;
}