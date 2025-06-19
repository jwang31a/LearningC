#include <stdio.h>

int main(int argc, char *argv[]) { //this is simple enough
    for (int i = argc - 1; i > 0; i--) {
        printf("%s ", argv[i]);
    }
    printf("\n");
    return 0;
}