#include <stdio.h>

int main(void) {
    int itemNumber, purchaseMonth, purchaseDay, purchaseYear;
    float unitPrice;
    printf("Enter item number: ");
    scanf("%d", &itemNumber);
    printf("Enter unit price: ");
    scanf("%7.2f", &unitPrice);
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &purchaseMonth, &purchaseDay, &purchaseYear);
    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    printf("%d\t\t$%7.2f\t%d/%d/%d\n", itemNumber, unitPrice, purchaseMonth, purchaseDay, purchaseYear);
}