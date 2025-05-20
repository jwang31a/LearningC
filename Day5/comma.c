#include <stdio.h>

int main(void) {
    int sum, i, N = 10;
    /*
    sum = 0;
    for (i = 1; i <= N; i++)
        sum += i;
    */
   //rewritten as this where multiple variables can be initialized
    for (sum = 0, i = 1; i <= N; i++)
        sum += i;
    printf("%d\n", sum);
    return 0;
}