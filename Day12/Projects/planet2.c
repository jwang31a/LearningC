#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

int ignorecasecmp(char *i, char *j) {
    for (;; i++, j++) {
        int d = tolower(*i) - tolower(*j);
        if (d != 0 || !*i) { //second condition is necessary to see if we reach the end of the first string (null char)
            return d;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    char *planets[] = {
        "Mercury", "Venus", "Earth", "Mars",
        "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"
    };
    int i, j;
    for (int i = 1; i < argc; i++) { //goes through each command line argument
        for (j = 0; j < NUM_PLANETS; j++) {
            if (ignorecasecmp(argv[i], planets[j]) == 0) {
                printf("%s is planet %d\n", argv[i], j + 1);
                break;
            }
        }
        if (j == NUM_PLANETS) {
            printf("%s is not a planet\n", argv[i]);
        }
    }
    return 0;
}