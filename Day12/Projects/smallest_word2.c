#include <stdio.h>
#include <string.h>

#define LENGTH 20

/*
this is not how the textbook does it but pointer practice is always welcome
*/
void read_line(char *str) {
    char *i = str, c;
    while ((c = getchar()) != '\n') {
        if (i < str + LENGTH) {
            *i++ = c;
        }
    }
    *i = '\0';
}

int main(void) {
    char shortest[LENGTH + 1], longest[LENGTH + 1], str[LENGTH + 1];
    printf("Enter word: ");
    read_line(str);
    strcpy(longest, strcpy(shortest, str)); //2 commented lines condensed into 1
    // strcpy(shortest, str);
    // strcpy(longest, str);
    while (strlen(str) != 4) {
        printf("Enter word: ");
        read_line(str);
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