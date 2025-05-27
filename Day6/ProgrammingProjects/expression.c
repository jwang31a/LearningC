#include <stdio.h>
#include <ctype.h>

/*
order of operations not taken into account
(probably takes a stack to do, which is complex for this stage)
*/

int main(void) {
    float result, n;
    char op;
    printf("Enter an expression: ");
    scanf("%f", &result);
    while ((op = getchar()) != '\n') { //maybe this isn't actually sketchy loop behavior?
        scanf("%f", &n);
        switch (op) {
            case '+':
                result += n;
                break;
            case '-':
                result -= n;
                break;
            case '*':
                result *= n;
                break;
            case '/':
                result /= n;
                break;
        }
    }
    printf("Value of expression: %g\n", result); //g for truncated 0s
    return 0;
}