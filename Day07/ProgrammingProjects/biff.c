#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100 //i don't like hardcoding this but i guess we have to

/*
a->4
b->8
e->3
i->1
o->0
s->5
+ many exclamation marks
*/

int main(void) {
    char c;
    int length = 0;
    int i = 0;
    char string[MAX_SIZE] = {0};
    printf("Enter message: ");
    while ((c = getchar()) != '\n') {
        string[i] = c;
        i++;
    }
    printf("In B1FF-speak: ");
    for (int j = 0; j < i; j++) {
        switch (toupper(string[j])) {
            case 'A':
                putchar('4');
                break;
            case 'B':
                putchar('8');
                break;
            case 'E':
                putchar('3');
                break;
            case 'I':
                putchar('1');
                break;
            case 'O':
                putchar('0');
                break;
            case 'S':
                putchar('5');
                break;
            default:
                putchar(string[j]);
                break;
        }
    }
    printf("!!!!!!!!!!!\n");
    return 0;
}