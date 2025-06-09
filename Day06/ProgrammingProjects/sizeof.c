#include <stdio.h>

int main(void) {
    printf("%zu\n", sizeof(int)); //4 bytes, 32 bits
    printf("%zu\n", sizeof(short)); //2 bytes, 16 bits
    printf("%zu\n", sizeof(long)); //8 bytes, 64 bits
    printf("%zu\n", sizeof(float)); //4 bytes, 32 bits
    printf("%zu\n", sizeof(double)); //8 bytes, 64 bits
    printf("%zu\n", sizeof(long double)); //16 bytes, 128 bits
    return 0;
}