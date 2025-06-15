#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50 //max number of reminders
#define MSG_LEN 60 //max length of reminder message

/*
small modifications so i can understand pointer arithmetic with multidimension arrays better
*/

int read_line(char str[], int n) {
    int c, i = 0;
    while ((c = getchar()) != '\n') {
        if (i < n) {
            str[i++] = c;
        }
    }
    str[i] = '\0';
    return i;
}

void print_reminders(char reminders[][63], int num_reminders) {
    for (int i = 0; i < num_reminders; i++) {
        printf(" %s\n", reminders[i]);
    }
}

void print_reminders_p(char (*reminders)[63], int num_reminders) {
    for (char (*s)[63] = reminders; s < num_reminders + reminders; s++) {
        printf(" %s\n", *s);
    }
}

int main(void) {
    char reminders[MAX_REMIND][MSG_LEN + 3]; //message length plus 3 for the day and a space
    char day_str[3], msg_str[MSG_LEN + 1]; //extra char for null char
    int day, i, j, num_remind = 0;
    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }
        printf("Enter day and reminder: ");
        scanf("%2d", &day); //makes sure the days are limited to 2 digits
        if (day == 0) {
            break; //this is our exit condition
        }
        sprintf(day_str, "%2d", day); //like printf, but outputs to a string
        read_line(msg_str, MSG_LEN);
        for (i = 0; i < num_remind; i++) { //this loop finds out where we insert the new reminder entry
            if (strcmp(day_str, reminders[i]) < 0) {
                break;
            }
        }
        for (j = num_remind; j > i; j--) { //this loop shifts everything after the place where we want to insert to the right by 1
            strcpy(reminders[j], reminders[j - 1]);
        }
        strcpy(reminders[i], day_str); //after shifting, there's an empty spot (that we can overwite) with the new entry
        strcat(reminders[i], msg_str);
        num_remind++;
    }
    print_reminders_p(reminders, num_remind);
    /*
    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++) {
        printf(" %s\n", reminders[i]);
    }
    */
    return 0;
}