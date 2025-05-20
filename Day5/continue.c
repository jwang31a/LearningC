#include <stdio.h>

/*
i made variable soup but at least it works
*/

int main(void) {
    int sum = 0, i = 0, j = 0;
    printf("Enter 10 integers to be summed: ");
    while (i < 10) {
        scanf("%d", &j);
        if (j == 0) {
            continue;
        }
        sum += j;
        i++;
        /*continue jumps to here*/
    }
    printf("sum = %d\n", sum);
    return 0;
}