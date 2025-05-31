#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

/*
probably not the best implementation, but it is what it is
i wonder if there's a way to get rid of all characters after the one you care about efficiently
i guess getchar could do it easily enough with a loop until enter

honestly this was pretty interesting to make
i feel like the games can go on for longer than expected but that's probably also fine
*/

/*
i wanted to make a roll function rather than generating a random number between 1 and 12
because the sum of two uniformly distributed random variables is approximately normal i believe
*/
int roll() {
    return rand() % 6 + 1;
}

bool craps() {
    int sum, point;
    bool done = false;
    sum = roll() + roll();
    printf("You rolled: %d\n", sum);
    if (sum == 7 || sum == 11) {
        printf("You win!\n");
        return true;
    } else if (sum == 2 || sum == 3 || sum == 12) {
        printf("You lose!\n");
        return false;
    } else {
        point = sum;
        printf("Your point is %d\n", point);
    }
    while (true) {
        sum = roll() + roll();
        printf("You rolled: %d\n", sum); //which takes precedent over the other: the point or the 7?
        if (sum == point) {
            printf("You win!\n");
            return true;
        } else if (sum == 7) {
            printf("You lose!\n");
            return false;;
        }
    }
}

void throwaway() {
    while (getchar() != '\n');
}

int main(void) {
    srand((unsigned) time(NULL));
    int wins = 0, losses = 0;
    while (true) {
        craps() ? wins++ : losses++;
        printf("Play again (Y/N)? ");
        if (tolower(getchar()) == 'y') {
            (void) throwaway(); //using the looped getchar that i talked about above
            // (void) getchar(); //have to deal with the enter character, void to make it clear that this value does not matter
            continue;
        } else {
            break;
        }
    }
    printf("Wins: %d  Losses: %d\n", wins, losses);
    return 0;
}