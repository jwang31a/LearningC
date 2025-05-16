#include <stdio.h>

int main(void) {
    int dec;
    int digit1, digit2, digit3, digit4, digit5;
    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &dec);
    // printf("In octal, your number is %o\n", dec); //technically this is illegal knowledge; textbook hasn't covered this yet
    digit5 = dec % 8;
    dec /= 8;
    digit4 = dec % 8;
    dec /= 8;
    digit3 = dec % 8;
    dec /= 8;
    digit2 = dec % 8;
    dec /= 8;
    digit1 = dec % 8;
    dec /= 8;
    printf("In octal, your number is %d%d%d%d%d\n", digit1, digit2, digit3, digit4, digit5);
    return 0;
}