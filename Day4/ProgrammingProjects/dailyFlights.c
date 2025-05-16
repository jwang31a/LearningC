#include <stdio.h>

/*
this way of calculating things is so cursed
*/

//functions not covered in textbook yet
int timeToMinutes(int hours, int minutes) {
    return 60 * hours + minutes; 
}

int main(void) {
    int departureHour, departureMinute, minutesSinceMidnight;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &departureHour, &departureMinute);
    minutesSinceMidnight = timeToMinutes(departureHour, departureMinute);
    printf("Closest departure time is ");
    if (minutesSinceMidnight < (timeToMinutes(8, 0) + timeToMinutes(9, 43)) / 2) {
        printf("8:00 a.m., arriving at 10:16 a.m.\n");
    } else if (minutesSinceMidnight < (timeToMinutes(11, 19) + timeToMinutes(9, 43)) / 2) {
        printf("9:43 a.m., arriving at 11:52 a.m.\n");
    } else if (minutesSinceMidnight < (timeToMinutes(11, 19) + timeToMinutes(12, 47)) / 2) {
        printf("11:19 a.m., arriving at 1:31 p.m.\n");
    } else if (minutesSinceMidnight < (timeToMinutes(12, 47) + timeToMinutes(14, 0)) / 2) {
        printf("12:47 p.m., arriving at 3:00 p.m.\n");
    } else if (minutesSinceMidnight < (timeToMinutes(14, 0) + timeToMinutes(15, 45)) / 2) {
        printf("2:00 p.m., arriving at 4:08 p.m.\n");
    } else if (minutesSinceMidnight < (timeToMinutes(15, 45) + timeToMinutes(19, 0)) / 2) {
        printf("3:45 p.m., arriving at 5:55 p.m.\n");
    } else if (minutesSinceMidnight < (timeToMinutes(19, 0) + timeToMinutes(21, 45)) / 2) {
        printf("7:00 p.m., arriving at 9:20 p.m.\n");
    } else {
        printf("9:45 p.m., arriving at 11:58 p.m.\n");
    }
    return 0;
}