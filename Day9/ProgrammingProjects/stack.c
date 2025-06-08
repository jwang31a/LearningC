#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

/*
modified stack to store char
then stack for parentheses or braces for matching (classic problem)
main function
*/

char contents[STACK_SIZE];
char top = 0;

void stack_overflow(void) {
    printf("Stack overflow (Parentheses/braces improperly nested)\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void) {
    printf("Stack underflow\n");
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

int main(void) {
    char c;
    printf("Enter parentheses and/or braces: ");
    while ((c = getchar()) != '\n') {
        if (c == '(' || c == '[' || c == '{') {
            push(c);
        } else if (c == ')' && pop() != '(') {
            printf("Parentheses/braces are improperly nested.\n");
            return 0;
        } else if (c == ']' && pop() != '[') {
            printf("Parentheses/braces are improperly nested.\n");
            return 0;
        } else if (c == '}' && pop() != '{') {
            printf("Parentheses/braces are improperly nested.\n");
            return 0;
        }
    }
    printf("Parentheses/braces are nested properly.\n");
    return 0;
}