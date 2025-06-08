#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

/*
uses modified stack that stores chars
uses it to do reverse polish notation (rpn)
*/

char contents[STACK_SIZE];
char top = 0;

void stack_overflow(void) {
    printf("Expression is too complex.\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void) {
    printf("Not enough operands in expression.\n");
    exit(EXIT_FAILURE);
}

void make_empty(void) {
    top = 0;
}

bool is_empty(void) {
    return top == 0;
}

bool is_full(void) {
    return top == STACK_SIZE;
}

void push(char i) {
    if (is_full()) {
        stack_overflow(); //interesting
    } else {
        contents[top++] = i;
    }
}

char pop(void) {
    if (is_empty()) {
        stack_underflow();
    } else {
        return contents[--top];
    }
}

/*
this should really be a switch statement but i already made it an if else if else statement
*/
int main(void) {
    int value = 0;
    char c, n, m;
    for (;;) {
        printf("Enter an RPN expression: ");
        for (;;) {
            scanf(" %c", &c);
            if (isdigit(c)) {
                push(c - '0');
            } else if (c == '+') {
                push(pop() + pop());
            } else if (c == '-') {
                m = pop();
                n = pop();
                push(n - m);
            } else if (c == '*') {
                n = pop();
                m = pop();
                push(n * m);
            } else if (c == '/') {
                m = pop();
                n = pop();
                push(n / m);
            } else if (c == '=') {
                printf("Value of expression: %d\n", pop());
                break;
            } else {
                exit(EXIT_FAILURE);
            }
        }
        make_empty();
    }
    return 0;
}