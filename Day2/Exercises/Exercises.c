#include <stdio.h>

/*
1) output of following calls of printf: (* denotes spaces)
 a) printf("%6d,%4d", 86, 1040);
    ****86,1040
 b) printf("%12.5e", 30.253);
    *3.02530e+01
 c) printf("%.4f", 83.162);
    83.1620
 d) printf("%-6.2g", .0000009979);
    9.979e-07
    is actually 1e-06 b/c 2 sigfigs?
*/

/*
3) are pairs of scanf format strings equivalent?
 a) "%d" versus " %d"
    no, because scanf expects a preceding space in the right, while there may or may not be one on the left
    yes, the preceding space may or may not be there, but either way it's skipped
 b) "%d-%d-%d" versus "%d -%d -%d"
    no, because spaces are not expected in the left, while one space is expected on the right
 c) "%f" versus "%f "
    yes
    no because for the last one to terminate, i need another whitespace
 d) "%f,%f" versus "%f, %f"
    no, because a space is expected on the right and no spaces are expected on the left
    yes, since whitespace matched
*/

void exercise1() {
    printf("%6d,%4d", 86, 1040);
    printf("\n");
    printf("%12.5e", 30.253);
    printf("\n");
    printf("%.4f", 83.162);
    printf("\n");
    printf("%-6.2g", .0000009979);
    printf("\n");
}

void exercise2(float x) {
    printf("|%-8.1e|\n", x);
    printf("|%10.6e|\n", x);
    printf("|%-8.3f|\n", x);
    printf("|%6.0f|\n", x);
}

void exercise3a() {
    int x, y;
    printf("comparing \"%%d\" and \" %%d\" ");
    scanf("%d", &x);
    scanf(" %d", &y);
    printf("x = %d\n", x);
    printf("y = %d\n", y);
}

void exercise3b() {
    int a, b, c, x, y, z;
    printf("comparing \"%%d-%%d-%%d\" and \"%%d -%%d -%%d\" ");
    scanf("%d-%d-%d", &a, &b, &c);
    scanf("%d -%d -%d", &x, &y, &z);
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    printf("x = %d, y = %d, z = %d\n", x, y, z);
}

void exercise3c() {
    float x, y;
    printf("comparing \"%%f\" and \"%%f \" ");
    scanf("%f", &x);
    scanf("%f ", &y);
    printf("x = %f\n", x);
    printf("y = %f\n", y);
}

void exercise3d() {
    float a, b, x, y;
    //%f,%f versus %f, %f
    scanf("%f,%f", &a, &b);
    scanf("%f, %f", &x, &y);
    printf("a = %f, b = %f\n", a, b);
    printf("x = %f, y = %f\n", x, y);
}

int main(void) {
    float x = 2147.483647f;
    float y = 1.23f;
    // exercise1();
    exercise2(x);
    printf("----------\n");
    exercise2(y);
    // exercise3a();
    // exercise3b();
    // exercise3c();
    exercise3d();
    return 0;
}