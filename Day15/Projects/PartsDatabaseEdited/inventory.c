#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    int price; //added in project 16.4
};

/*
looks up part number in inventory array
returns array index if part number found
-1 if not found
*/
int find_part(int number, const struct part inventory[], int num_parts) {
    for (int i = 0; i < num_parts; i++) {
        if (inventory[i].number == number) {
            return i;
        }
    }
    return -1;
}

void insert(struct part inventory[], int *num_parts) {
    int part_number;
    if (*num_parts == MAX_PARTS) {
        printf("Database is full; can't add more parts.\n");
        return;
    }
    printf("Enter part number: ");
    scanf("%d", &part_number);
    if (find_part(part_number, inventory, *num_parts) >= 0) {
        printf("Part already exists.\n");
        return;
    }
    inventory[*num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[*num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[*num_parts].on_hand);
    printf("Enter price: ");
    scanf("%d", &inventory[*num_parts].price);
    int i = *num_parts;
    while (i > 0 && inventory[i].number < inventory[i - 1].number) {
        struct part temp = inventory[i];
        inventory[i] = inventory[i - 1];
        inventory[i - 1] = temp;
    }
    (*num_parts)++;
}

void search(struct part inventory[], int num_parts) {
    int i, number;
    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, inventory, num_parts);
    if (i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
        printf("Price: %d\n", inventory[i].price);
    } else {
        printf("Part not found.\n");
    }
}

void update(struct part inventory[], int num_parts) {
    int i, number, change;
    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, inventory, num_parts);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    } else {
        printf("Part not found.\n");
    }
}

void print(struct part *inventory, int num_parts) { //changes from 16.2
    printf("Part number   Part Name                  "
        "Quantity on Hand   Price\n");
    for (int i = 0; i < num_parts; i++) {
        printf("%7d       %-25s%11d   %11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand, inventory[i].price);
    }
}

int main(void) {
    char code;
    struct part inventory[MAX_PARTS]; //modification from 16.3
    int num_parts = 0;
    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n');
        switch (code) {
            case 'i':
                insert(inventory, &num_parts);
                break;
            case 's':
                search(inventory, num_parts);
                break;
            case 'u':
                update(inventory, num_parts);
                break;
            case 'p':
                print(inventory, num_parts);
                break;
            case 'q':
                return 0;
            default:
                printf("Illegal code\n");
        }
        printf("\n");
    }
}