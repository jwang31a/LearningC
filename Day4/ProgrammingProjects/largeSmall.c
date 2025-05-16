#include <stdio.h>

/*
divide and conquer to achieve minimum number of if (else) statements (4)
*/

int main(void) {
    int a, b, c, d, min, max, lmax, lmin, rmax, rmin;
    printf("Enter four integers: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a < b) {
        lmax = b;
        lmin = a;
    } else {
        lmax = a;
        lmin = b;
    }
    if (c < d) {
        rmax = d;
        rmin = c;
    } else {
        rmax = c;
        rmin = d;
    }
    if (lmax < rmax) {
        max = rmax;
    } else {
        max = lmax;
    }
    if (lmin < rmin) {
        min = lmin;
    } else {
        min = rmin;
    }
    printf("Largest: %d\n", max);
    printf("Smallest: %d\n", min);
    return 0;
}