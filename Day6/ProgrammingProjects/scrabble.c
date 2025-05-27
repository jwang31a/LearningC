#include <stdio.h>
#include <ctype.h>

int main(void) {
    int score = 0; //remember to initialize otherwise strange values
    printf("Enter a word: ");
    char c = toupper(getchar()); //could be done with tolower as well
    while (c != '\n') {
        switch (c) {
            case 'A': case 'E': case 'I': case 'L': case 'N': case 'O': case 'R': case 'S': case 'T': case 'U':
                score += 1;
                break;
            case 'D': case 'G':
                score += 2;
                break;
            case 'B': case 'C': case 'M': case 'P':
                score += 3;
                break;
            case 'F': case 'H': case 'V': case 'W': case 'Y':
                score += 4;
                break;
            case 'K':
                score += 5;
                break;
            case 'J': case 'X':
                score += 8;
                break;
            case 'Q': case 'Z':
                score += 10;
                break;
        }
        c = toupper(getchar());
    }
    printf("Srabble value: %d\n", score);
    return 0;
}