/*
also includes 3
*/

#include <stdio.h>

float calculateVolume(int radius) {
    return (4.0f / 3.0f) * 3.1415926 * radius * radius * radius;
}

int main(void) {
    printf("What is the radius of your sphere? ");
    int radius;
    float volume;
    scanf("%d", &radius); //do not assign radius here
    volume = calculateVolume(radius);
    printf("The volume is %f.\n", volume);
}