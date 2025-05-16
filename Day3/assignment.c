#include <stdio.h>

int main(void) {
    int i = 72.99f; //assigning float to int truncates
    printf("%d\n", i);
    float f = 100; //assigning int to float just adds a .0
    printf("%f\n", f);
    int j, k;
    i = j = k = 0; //goes from right to left
    printf("%d, %d, %d\n", i, j, k);
    // 12 = i; //gcc will say that lvalue required as left operand
}

/*
Simple assignment: variable copies the value form an expression
  - expressions can be a constant, variable, or more complicated expression
assignment is an operator
operator side effects: evaluating expression i = 0 has result 0 and side effect of assignment of 0 to i
assignment requires L value as left operand, which is stored in memory
  - variables are, not expressions or constants
  - other types exist as well (discussed later)
Compound assignment (slightly different from simple assignment, so not completely equivalent)
  - also increment and decrement operators
  - both prefix and postfix
      - side effects: prefix returns i + 1 and increments i, postfix returns i but still increments i
postfix operations have highest priority, then increment/unary, then arithmetic, and lastly assignment
subexpression order may vary, so for example in (a + b) * (c - d), we don't know for sure whether the left or right is evaluated first
  - subexpression order usually doesn't matter, unless one of them is an assignment (avoid)
*/