#include <stdbool.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void make_empty(void) {
    top = 0;
}

bool is_empty(void) {
    return top == 0;
}

bool is_full(void) {
    return top == STACK_SIZE;
}

void push(int i) {
    if (is_full()) {
        stack_overflow(); //interesting
    } else {
        contents[top++] = i;
    }
}

int pop(void) {
    if (is_empty) {
        stack_underflow();
    } else {
        return contents[--top];
    }
}