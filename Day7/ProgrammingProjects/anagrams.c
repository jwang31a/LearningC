#include <stdio.h>
#include <ctype.h>

#define ALPHABET 26 //length of the alphabet array

/*
two words are anagrams if they are permutations of the same letters
*/

/*
have to pass arrays as a pointer (to the first element)
*/
void printArray(int* alphabet) {
    for (int i = 0; i < ALPHABET; i++) {
        printf("%d ", alphabet[i]);
    }
    printf("\n");
}

int main(void) {
    int alphabet[ALPHABET] = {0};
    char c;
    printf("Enter first word: ");
    while ((c = getchar()) != '\n') {
        if (isalpha(tolower(c))) {
            alphabet[c - 'a']++;
        }
    }
    printf("Enter second word: ");
    while ((c = getchar()) != '\n') {
        if (isalpha(tolower(c))) {
            alphabet[c - 'a']--;
        }
    }
    int i = 0;
    for (i; i < ALPHABET; i++) {
        if (alphabet[i] != 0) {
            break;
        }
    }
    if (i == ALPHABET) {
        printf("The words are anagrams.\n");
    } else {
        printf("The words are not anagrams.\n");
    }
}