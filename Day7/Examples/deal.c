#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/*
time function returns current time in single number
srand initializes C's random number generator, passing time prevents dealing same cards every time
rand produces pseudorandom number, modulo that by # of ranks or suits for a random rank or suit
*/

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void) {
    bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
    int num_cards, rank, suit;
    const char rank_code[] = {'2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k', 'a'};
    const char suit_code[] = {'c', 'd', 'h', 's'};

    srand((unsigned) time(NULL)); //for a random number
    printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);
    printf("Your hand: ");
    while (num_cards > 0) {
        suit = rand() % NUM_SUITS;
        rank = rand() % NUM_RANKS;
        if (!in_hand[suit][rank]) {
            in_hand[suit][rank] = true;
            num_cards--;
            printf(" %c%c", rank_code[rank], suit_code[suit]);
        }
    }
    printf("\n");
    return 0;
}