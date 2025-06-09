#include <stdio.h>
#include <ctype.h>

int main(void) {
    int vowels = 0;
    char c;
    printf("Enter a sentence: ");
    while ((c = tolower(getchar())) != '\n') { //this is so sketchy but i guess it works?
        switch (c) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                vowels++;
                break; 
        }
    }
    printf("Your sentence contains %d vowels.\n", vowels);
    return 0;
}