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