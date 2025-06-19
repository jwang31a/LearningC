#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50 //max number of reminders
#define MSG_LEN 60 //max length of reminder message
#define TIME 12

/*
updated from example in previous chapter
*/

void read_line(char *str) {
    char *i = str, c;
    while ((c = getchar()) != '\n') {
        if (i < str + MSG_LEN) {
            *i++ = c;
        }
    }
    *i = '\0';
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

void flush() { //this flushes all unused characters if necessary
    while (getchar() != '\n');
}

int main(void) {
    char reminders[MAX_REMIND][MSG_LEN + TIME + 1];
    char time_str[TIME], msg_str[MSG_LEN + 1];
    int month, day, hour, minute, i, j, num_remind = 0;
    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }
        printf("Enter reminder (\"Formatted mm/dd hh:mm reminder\"): ");
        scanf("%2d/%2d", &month, &day);
        if (month == 0 || day == 0) { //modified to add month = 0 since that's the first thing to be read
            break; //this is our exit condition
        } else if (day > 31 || day < 0 || month > 12 || month < 0) {  //invalid dates mean repeat
            flush(); //because we stop early, we need to make sure the buffer is clean for the next input (we've read partially, we need to get rid of the rest)
            continue;
        }
        scanf("%2d:%2d", &hour, &minute);
        if (hour < 0 || hour > 24 || minute < 0 || minute > 60) {
            flush();
            continue;
        }
        sprintf(time_str, "%.2d/%.2d %.2d:%.2d", month, day, hour, minute);
        read_line(msg_str);
        for (i = 0; i < num_remind; i++) { //this loop finds out where we insert the new reminder entry
            if (strcmp(time_str, reminders[i]) < 0) {
                break;
            }
        }
        for (j = num_remind; j > i; j--) { //this loop shifts everything after the place where we want to insert to the right by 1
            strcpy(reminders[j], reminders[j - 1]);
        }
        strcpy(reminders[i], time_str); //after shifting, there's an empty spot (that we can overwite) with the new entry
        strcat(reminders[i], msg_str);
        num_remind++;
    }
    print_reminders_p(reminders, num_remind);
    return 0;
}