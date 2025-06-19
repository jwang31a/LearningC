#include <stdio.h>
#include <string.h>

/*
lesson learned: read the instructions properly and you won't have code that makes no sense
*/

int main(void) {
    int month, day, year;
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);
    printf("You entered the date %s %d, %d\n", months[month - 1], day, year);
    return 0;
}