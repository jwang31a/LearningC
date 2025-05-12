#include <stdio.h>

/*
i would use loops but textbook hasn't covered them yet
*/

int main(void) {
    int oneone, onetwo, onethree, onefour;
    int twoone, twotwo, twothree, twofour;
    int threeone, threetwo, threethree, threefour;
    int fourone, fourtwo, fourthree, fourfour;
    printf("Enter the numbers from 1 to 16 in any order:\n");
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &oneone, &onetwo, &onethree, &onefour,
    &twoone, &twotwo, &twothree, &twofour, &threeone, &threetwo, &threethree, &threefour,
    &fourone, &fourtwo, &fourthree, &fourfour);
    int row1 = oneone + onetwo + onethree + onefour;
    int row2 = twoone + twotwo + twothree + twofour;
    int row3 = threeone + threetwo + threethree + threefour;
    int row4 = fourone + fourtwo + fourthree + fourfour;
    int col1 = oneone + twoone + threeone + fourone;
    int col2 = onetwo + twotwo + threetwo + fourtwo;
    int col3 = onethree + twothree + threethree + fourthree;
    int col4 = onefour + twofour + threefour + fourfour;
    int dia1 = oneone + twotwo + threethree + fourfour;
    int dia2 = onefour + twothree + threetwo + fourone;
    printf("%2d %2d %2d %2d\n", oneone, onetwo, onethree, onefour);
    printf("%2d %2d %2d %2d\n", twoone, twotwo, twothree, twofour);
    printf("%2d %2d %2d %2d\n", threeone, threetwo, threethree, threefour);
    printf("%2d %2d %2d %2d\n", fourone, fourtwo, fourthree, fourfour);
    printf("Row sums: %d %d %d %d\n", row1, row2, row3, row4);
    printf("Column sums: %d %d %d %d\n", col1, col2, col3, col4);
    printf("Diagonal sums: %d %d\n", dia1, dia2);    
    return 0;
}