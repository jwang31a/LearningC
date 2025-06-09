#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

int secret;

void initialize_number_generator(void) {
    srand((unsigned) time(NULL));
}

void choose_secret_number(void) {
    secret = rand() % 100 + 1;
}

void read_guesses(void) {
    int guess, num_guesses = 0;
    for (;;) {
        num_guesses++;
        printf("Enter guess: ");
        scanf("%d", &guess);
        if (guess == secret) {
            printf("You won in %d guesses!\n\n", num_guesses);
            return;
        } else if (guess < secret) {
            printf("Too low; try again.\n");
        } else {
            printf("Too high; try again.\n");
        }
    }
}

int main(void) {
    char command;
    initialize_number_generator();
    do {
        choose_secret_number();
        printf("A new number has been chosen.\n");
        read_guesses();
        printf("Play again? (Y/N) ");
        scanf(" %c", &command);
        printf("\n");
    } while (command == 'y' || command == 'Y');
    return 0;
}