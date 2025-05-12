#include <stdio.h>

int main(void) {
    int num1, denom1, num2, denom2, result_num, result_denom;
    printf("Enter first fraction: ");
    scanf("%d/%d", &num1, &denom1);
    printf("Enter second fraction: ");
    scanf("%d/%d", &num2, &denom2);
    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;
    printf("The sum is %d/%d\n", result_num, result_denom);
    return 0;
}

/*
extras from the q&a:
  - %i is also a conversion specifier that works like %d for printf, but in scanf, it can also read octal, decimal, hexadecimal
      - 0 prefix means octal, 0x prefix means hex
      - strange results if accidental 0 prefix inserted
  - %% is treated as a %
  - \t is the tab escape, but how many spaces a tab is depends
*/