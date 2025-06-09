#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int grade;
    printf("Grade: ");
    scanf("%d", &grade);
    /*
    if (grade == 4)
        printf("Excellent");
    else if (grade == 3)
        printf("Good");
    else if (grade == 2)
        printf("Average");
    else if (grade == 1)
        printf("Poor");
    else if (grade == 0)
        printf("Failing");
    else
        printf("Illegal grade");
    */
    // cascaded if can be turned into switch statement
    switch (grade) {
        case 4:
            printf("Excellent");
            break;
        case 3:
            printf("Good");
            break;
        case 2:
            printf("Average");
            break;
        case 1:
            printf("Poor");
            break;
        case 0:
            printf("Failing");
            break;
        default:
            printf("Illegal grade");
            break;
    }
    return 0;
}

/*
alternative to cascaded if is the switch statement
breaks inside case just lead to statement after switch
if expression doesn't match any of the cases, then default case
switch (controlling expression) {
    case constant-expression : statements
    ...
    case constant-expression : statements
    default : statements
}
controlling expression is an integer expression
  - chars and ints can be tested
  - but not floats or strings
case label with a constant expression
  - does not contain variables or function calls
  - constant expressions may also be a character
statements do not need to be surrounded by braces
order of cases doesn't matter (default not necessarily last)
cases also don't necessarily need statements:

switch (grade) {
    case 4:
    case 3:
    case 2:
    case 1:
        printf("Passing");
        break;
    case 0:
        printf("Failing");
        break;
    default:
        printf("Illegal grade");
        break;
}

can be simplified to:

switch (grade) {
    case 4: case 3: case 2: case 1:
        printf("Passing");
        break;
    case 0:
        printf("Failing");
        break;
    default:
        printf("Illegal grade");
        break;
}

no case labels with ranges
default case not necessary, just passes to next statement after switch
breaks are necessary if you only want one output
  - without breaks, control falls through to next statement (case labels ignored)
  - any fall throughs should be pointed out with a comment for best practice
*/