#include <stdio.h>

int main(void) {
    int areaCode, telephonePrefix, lineNumber;
    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%d)%d-%d", &areaCode, &telephonePrefix, &lineNumber);
    printf("You entered %d.%d.%4.4d\n", areaCode, telephonePrefix, lineNumber);
}