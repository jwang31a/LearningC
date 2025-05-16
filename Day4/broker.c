#include <stdio.h>

int main(void) {
    float commission, value;
    printf("Enter value of trade: ");
    scanf("%f", &value);
    if (value < 2500.00f) {
        commission = 30.00f + 0.017f * value;
    } else if (value < 6250.00f) { //could have written this so that value is between 2500 and 6250, but not necessary
        commission = 56.00f + 0.0066f * value;
    } else if (value < 20000.00f) {
        commission = 76.00f + 0.0034f * value;
    } else if (value < 50000.00f) {
        commission = 100.00f + 0.0022f * value;
    } else if (value < 500000.00f) {
        commission = 155.00f + 0.0011f * value;
    } else {
        commission = 255.00f + 0.0009f * value;
    }
    if (commission < 39.00f) {
        commission = 39.00f;
    }
    printf("Commission: $%.2f\n", commission);
    return 0;
}

/*
selection statements: if and switch
iteration statements: while, do, for
jump statements: break, continue, goto (return)

relational operators: <, >, <=, >=
  - can compare operands of mixed types (so int and float comparisons are valid)
equality operators: ==, != (lower precedence than relational)
logical operators: ! (unary), &&, ||
if and else clauses work just like in java, no reason to redo
else if statements (cascaded statements)
else not necessarily needed

dangling else example: which if statement does the else belong to?
if (y != 0)
    if (x != 0)
        result = x / y;
else
    printf("Error: y is equal to 0\n");
else statements belong to the closest if statement (in this case the nested one)
just use brackets

conditional operator uses ? and : (ternary operator)
  - expr1 ? expr2 : expr3
  - ocnditional expression

C89 doesn't have a proper Boolean type
  - can use flags with value 0 or 1, but not very understandable
  - alternatively:
      - #define TRUE 1
      - #define FALSE 0
  - further, define macro that can be used as type:
      - #define BOOL int
      - BOOL flag;
C99 has the _Bool type (really just an integer in disguise)
  - can only be assigned 0 or 1, any assignments of nonzero values will default to 1
  - can perform arithmetic on and print _Bool
  - <stdbool.h> header supplies bool macro and true and false macros (1 and 0)
      - very handy when working with booleans, so usually include
*/