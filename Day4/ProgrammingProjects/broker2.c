#include <stdio.h>

int main(void) {
    float commission, shares, sharePrice, rival;
    printf("Enter number of shares: ");
    scanf("%f", &shares);
    printf("Enter price per share: ");
    scanf("%f", &sharePrice);
    int value = shares * sharePrice;
    if (value < 2500.00f) {
        commission = 30.00f + 0.017f * value;
    } else if (value < 6250.00f) { //could have written this so that value is between 2500 and 6250, but not necessary
        commission = 56.00f + 0.0066f * value;
    } else if (value < 20000.00f) {
        commission = 76.00f + 0.0034f * value;
    } else if (value < 50000.00f) {
        commission = 100.00f + 0.0022f * value;
    } else if (value < 500000.00f) {
        commission = 155.00f + 0.0011f * value;
    } else {
        commission = 255.00f + 0.0009f * value;
    }
    if (commission < 39.00f) {
        commission = 39.00f;
    }
    if (shares < 2000) {
        rival = 33.00f + 0.03f * shares;
    } else {
        rival = 33.00f + 0.02f * shares;
    }
    printf("Our commission: $%.2f\n", commission);
    printf("Rival's commission: $%.2f\n", rival);
    return 0;
}