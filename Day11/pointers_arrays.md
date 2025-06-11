# pointers and arrays

* arithmetic on pointers to array elements as a replacement for subscripting
* cool for strings and more advanced uses of pointers
* primary reason to use pointers for arrays was efficiency, although that matters very little nowadays

## pointer arithmetic

* ```C
    int a[10], *p;
    p = &a[0];
    ```
    * access a[0] through p, i.e. through `*p = 5;`
* C supports adding integer to or subtracting integer from pointer and subtracting pointer from pointer
* ```C
    int a[10], *p, *q, i;
    ```
    * will be used in examples below

### adding integer to pointer

* adding int j to pointer p yields pointer to element j places after the one that p points to
    * if p points to a[i], then p + j points to a[i + j] (if a[i + j] exists)

### subtracting integer from pointer

* works similarly to addition: if p points to a[i], then p - j points to a[i - j]

### subtracting one pointer from another

* result of one pointer subtracted from another is the distance (measured in array elements) between pointers
    * if p points to a[i] and q points to a[j], then p - q is equal to i - j
* make sure that both pointers point to an array element in the same array to prevent undefined behavior

### comparing pointers

* compare using relational operators (<, <=, >, >=) and equality (==, !=)
    * relational only useful when both pointers point to  elements of the same array
* ```C
    p = &a[5];
    q = &a[1];
    p <= q; //0 (false)
    p >= q; //1 (true)
    ```

### pointers to compound literals

* ```C
    int *p = (int []){3, 0, 3, 4, 1};
    ```
    * here, p points to the first element of the array
    * just a shorthand for:
    * ```C
        int a[] = {3, 0, 3, 4, 1};
        int *p = &a[0];
        ```

## pointers for array processing

* ```C
    #define N 10
    ...
    int a[N], sum, *p;
    ...
    sum = 0;
    for (p = &a[0]; p < &a[N]; p++)
        sum += *p;
    ```
    * this sums the elements of a
    * even though a[N] doesn't exist, we can do it because the loop only looks at the address, not the value
    * supposedly saves execution time, although this is compiler dependent

### combining * and ++ operators

* storing value into array element and advancing to next element:
    * `a[i++] = j;
    * can also be done with `p++ = j;` if p points to array element
    * read by compiler as `*(p++) = j;`, where postfix takes precedence over *, value p++ is p
* \*p++, \*(p++): value of expression is *p before increment, then increment p
* (*p)++: value of expression is *p before increment, increment *p later
* *++p, *(++p): increment p first, value is *p after increment
* ++\*p or ++(\*p): increment *p first, value of expression is *p after increment
* this makes a lot more sense when you put the parentheses in and recognize that prefix/postfix takes precedence over indirection
* instead of:
* ```C
    for (p = &a[0]; p < &a[N]; p++)
        sum += *p;
    ```
* ```C
    p = &a[0];
    while (p < &a[N])
        sum += *p++;
    ```
* example using stack
* ```C
    int *top_ptr = &contents[0];
    ...
    void push(int i) {
        if (is_full()) {
            stack_overflow();
        } else {
            *top_ptr++ = i;
        }
    }

    int pop(void) {
        if (is_empty()) {
            stack_underflow();
        } else {
            return *--top_ptr;
        }
    }
    ```

## using array name as pointer

* ```C
    int a[10];
    *a = 7; //stores 7 in a[0]
    *(a + 1) = 12; //stores 12 in a[1]
    ```
* array subscripting is like pointer arithmetic
* array names can also serve as a pointer
* ```C
    for (p = a; p < a + N; p++)
        sum += *p;
    ```
    * however, we cannot assign new values through this, so this is wrong:
    * ```C
        while (*a != 0)
            a++;
        ```
    * easy fix is:
    * ```C
        p = a;
        while (*p != 0)
            p++;
        ```

### array arguments revisited

* when ordinary variable passed to function, value is copied so changes to the corresponding parameter don't affect variable
* when array is passed, we don't copy the array, but we create a copy of the pointer (that still points to the first element in the array)
    * that means the array is not protected against change
    * use const to denote that
    * this also does not affect time, since no copy of array is being made, just another pointer
    * array parameter can be declared as pointer if necessary
    * ```C
        int find_largest(int *a, int n) {
            ...
        }
        ```
    * this is equivalent to declaring an array
* we cannot treat pointer variables as arrays
* we can use array arithmetic to slice arrays

### pointers as array names

* ```C
    #define N 10
    ...
    int a[N], i, sum = 0, *p = a;
    ...
    for (i = 0; i < N; i++)
        sum += p[i];
    ```
* p[i] is treated as *(p + i)

## pointers and multidimensional arrays

* pointers can also point to elements of multidimensional arrays

### elements of multidimensional array

* 2d arrays stored in row major order
* nested for loop approach:
* ```C
    int a[NUM_ROWS][NUM_COLS];
    int row, col;
    ...
    for (row = 0; row < NUM_ROWS; row++)
        for (col = 0; col < NUM_COLS; col++)
            a[row][col] = 0;
    ```
* but a 1d representation will also work
* ```C
    int *p;
    ...
    for (p = &a[0][0]; p <= &a[NUM_ROWS - 1][NUM_COLS - 1]; p++)
        *p = 0;
    ```
    * each increment will go through a row column by column, then move to the next row once necessary
* probably some speed benefit with older compilers, but at the cost of readability

### processing rows of multidimensional array

* to visit elements of row i:
* `p = &a[i][0];` or `p = a[i];` for a pointer to the first element in row i
* ```C
    int a[NUM_ROWS][NUM_COLS], *p, i;
    ...
    for (p = a[i]; p < a[i] + NUM_COLS; p++)
        *p = 0;
    ```

### processing columns of multidimensional array

* columns are harder to deal with
* ```C
    int a[NUM_ROWS][NUM_COLS], (*p)[NUM_COLS], i;
    ...
    for (p = &a[0]; p < &a[NUM_ROWS]; p++)
        (*p)[i] = 0;
    ```
    * parentheses around *p are necessary to have a pointer to an array rather than an array of pointers
    * p++ advances to the next row

### using name of multidimensional array as pointer

* `int a[NUM_ROWS][NUM_COLS]`
    * a is not a pointer to a[0][0], but instead points to a[0] (row 0)
    * a has type int (*)[NUM_COLS] (pointer to integer array of length NUM_COLS)
* instead of:
    * ```C
        for (p = &a[0]; p < &a[NUM_ROWS]; p++)
            (*p)[i] = 0;
        ```
* simplify to:
    * ```C
        for (p = a; p < a + NUM_ROWS; p++)
            (*p)[i] = 0;
        ```
* to trick compiler into thinking multidimensional array is one dimensional:
    * ```C
        largest = find_largest(a[0], NUM_ROWS * NUM_COLS);
        ```
    * a[0] points to element 0 in row 0 and has type int *, so no compiler objections

## pointers and variable length arrays (c99)

* pointers can point to elements of variable length arrays in c99
* ```C
    void f(int n) {
        int a[n], *p;
        p = a;
        ...
    }
    ```
* when vla has more than one dimension, type of pointer depends on length of each dimension except first
* ```C
    void f(int m, int n) {
        int a[m][n], (*p)[n];
        p = a;
    }
    ```
    * p has a variably modified type since type of p depends on n
    * validity of assignment `p = a` can't necessarily be determined by compiler
* restriction of declaration of variably modified type inside body of function or function prototype
* pointer arithmetic still works
* ```C
    int a[m][n];
    int (*p)[n];
    for (p = a; p < a + m; p++) {
        (*p)[i] = 0;
    }
    ```

## extra notes

* p + j does not add j to address stored in p, but rather #of bytes of type p points to * j
    * so if p is type int *, then p + j will add 4j to the address
* apparently i[a] is the same as a[i] but this is terrible practice
* style of declaring array parameter as *a or a[]
    * probably depends on what we're using the array for inside the function