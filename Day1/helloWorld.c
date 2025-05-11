/*
My first C program!
*/

//directives go here, one liners, don't require ;
#include <stdio.h>

float feetToMeters(int feet, int inches) { //remember to look at the return type!
    float meters = 30.48f * feet + 2.54f * inches; //it's good to append f to designate float
    return meters;
}

float centimetersToFeet(float cm) {
    float feet = cm / 30.48f;
    return feet;
}

int boxVolume(int length, int width, int height) {
    return length * width * height;
}

int volumetricWeight(int volume) {
    return (volume + 165) / 166;
}

//main always return an int
int main(void) {
    printf("Hello World!\n"); //printf is the default print function
    //printf doesn't auto advance to the next line
    float meters = feetToMeters(5,10);
    printf("%.2f meters\n", meters); //printf like in java
    float feet = centimetersToFeet(177.8);
    printf("%.2f meters\n", feet);
    printf("%d pounds\n", volumetricWeight(boxVolume(12, 10, 8)));
    //this is problematic because it may cause crash or strange prints
    //gcc is nicer it seems, since it has default values
    /*
    float i;
    printf("%f\n", i);
    int j;
    printf("%d\n", j);
    */
    int k = 2147483647; //2147483647 is called an initializer, all variables require initializers
    int height, length, width = 10; //only useful for width, doesn't initialize length or height
    return 0; //return 0 signifies successful end to main function
}