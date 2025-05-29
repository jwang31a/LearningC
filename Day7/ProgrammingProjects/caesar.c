#include <stdio.h>
#include <ctype.h>

#define MESSAGE_LENGTH 80

/*
caesar cipher, replace each letter in message with another letter a fixed number of positions later in alphabet
wrap around if needed
for uppercase letters, use the uppercase shift
for lowercase letters, use the lowercase shift
for spaces and punctuation, do not shift at all
*/

int main(void) {
    printf("Enter message to be encrypted: ");
    char c;
    char message[MESSAGE_LENGTH];
    int i = 0;
    while ((c = getchar()) != '\n') {
        message[i++] = c; 
    }
    int shift;
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);
    for (int i = 0; i < MESSAGE_LENGTH && message[i] != 0; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            c = ((message[i] - 'A') + shift) % 26 + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            c = ((message[i] - 'a') + shift) % 26 + 'a';
        } else {
            c = message[i];
        }
        printf("%c", c);
    }
    printf("\n");
    return 0;
}