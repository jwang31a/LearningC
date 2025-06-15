#include <stdio.h>
#include <string.h>

int main(void) {
    char str[10], *s = str;
    strcpy(s, "abc");
    while (*s) {
        s++;
    }
    printf("%d\n", *s); //s pointing at first empty char
    printf("%p\n", &s);
    s = str;
    while (*s++);
    printf("%d\n", *s); //s points past empty char?
    printf("%p\n", &s);
    //okay so they point at the same place
    return 0;
}