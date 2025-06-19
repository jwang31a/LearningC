#include <stdio.h>
#include <string.h>

#define LENGTH 20

int main(void) {
    char shortest[LENGTH + 1], longest[LENGTH + 1], str[LENGTH + 1];
    printf("Enter word: ");
    scanf("%20s", str);
    strcpy(shortest, str);
    strcpy(longest, str);
    while (strlen(str) != 4) {
        printf("Enter word: ");
        scanf("%20s", str);
        if (strcmp(shortest, str) > 0) {
            strcpy(shortest, str);
        }
        if (strcmp(longest, str) < 0) {
            strcpy(longest, str);
        }

    }
    printf("Smallest word: %s\n", shortest);
    printf("Longest word: %s\n", longest);
    return 0;
}   