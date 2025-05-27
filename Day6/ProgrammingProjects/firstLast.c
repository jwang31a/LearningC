#include <stdio.h>
#include <ctype.h>

/*
surely this isn't the preferred solution
ain't no way right?
*/

int main(void) {
    char first, c;
    printf("Enter a first and last name: ");
    while ((c = getchar()) == ' '); //more incredibly sketchy behavior
    first = toupper(c);
    while ((c = getchar()) != ' ');
    while ((c = getchar()) != '\n') {
        printf("%c", c);
    }
    printf(", %c.\n", first);
    return 0;
}