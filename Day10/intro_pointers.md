# introduction to pointers

* 1 of 3 chapters dedicated to pointers
* this will discuss introductory concepts of pointers

## pointer variables

* memory in computers divided into bytes (each containing 8 bits)
* unique address for each byte, so if n bytes, addresses can range from 0 to n - 1
* both instructions and data occupy memory (one or more bytes each)
    * if a variable occupies multiple bytes, the first byte is the address
* a pointer variable is a variable storing an address
* `int *p;` (preceded by asterisk)
    * p is a pointer variable capable of pointing to objects of type int (does not have to poin to memory belonging to variable, also meaning of object will change soon)
* every pointer variable can only point to the referenced type
    * the referenced type can be pointers as well (pointers to pointers)

## addresses and indirection operators

* to find address of variable, use & (address) operator
    * if x is variable, &x is the address of x in memory
* to gain access to object that pointer points to, use * (indirection) operator
    * if p is pointer, then *p represents the object to which p currently points to

### address operator

* `int *p;` points nowhere in particular, so init first
* ```C
    int i, *p;
    ...
    p = &i;
    ```
    * this makes p point to i by assigning address of i to variable p
* ```C
    int i;
    int *p = &i;
    ```
    * also valid
    * `int i, *p = &i;` combined

### indirection operator

* use * operator to access what's stored in the object
* `printf("%d\n", *p)` prints value of i if p points to i
    * displays the value of i, not its address
* *p is an alias for i
    * changing value of *p also changes value of i
* ```C
    p = &i;
    i = 1;
    printf("%d\n", i); //prints 1
    printf("%d\n", *p); //prints 1;
    *p = 2;
    printf("%d\n", i); //prints 2
    printf("%d\n", *p); //prints 2
    ```
    * a diagram representation may help with this
* do not apply indirection toi uninitialized pointer variable
* assigning value to *p is also dangerous

### pointer assignment

* assignment operator can be used to copy pointers
* ```C
    int i, j, *p, *q;
    p = &i;
    q = p; //both q and p hold address to i, point to the same place
    *p = 1;
    *q = 2; //since p and q point to the same place, updating one will update the others
    ```
* `q = p` is not the same as `*q = *p`
    * first statement is pointer assignment
* ```C
    p = &i; //p points to i
    q = &j; //q points to j
    i = 1; //set value of i
    *q = *p; //value that p points to (value of i) copied into what q points to (variable j)
    //in the end, although p and q store the same value, they don't point to the same value
    //this may be useful for shallow copy vs deep copy though
    ```

## pointers as arguments

* pointers can be used as function arguments
* sometimes we want to change the value of something we pass in (pass by value can be annoying)
* instead of passing a variable, we pass a pointer to the variable
* ```C
    void decompose(double x, long *int_part, double *frac_part) {
        *int_part = (long) x;
        *frac_part = x - *int_part;
    }
    ```
    * prototype `void decompose(double, long *, double *);
    * called using `decompose(3.14159, &i, &d);`
    * arguments used are pointers to i and d, so i and d contain the int and frac parts respectively
* we've done this with scanf, the & operator is used to tell scanf where to put input value
    * ```C
        int i, *p;
        ...
        p = &i;
        scanf("%d", p);
        ```
    * scanf doesn't have to take & operators necessarily
    * remember to not do something like `scanf("%d", &p);`
        * this puts an integer into i

### const to protect arguments

* when we call function and pass pointer to variable, assuption that function will modify variable
* possibility that we peek at the value
    * maybe the variable requires a large amount of storage, so we only pass the pointer to save time and space
* const to document that function won't change object whose address passed to function
    * ```C
        void f(const int *p) {
            *p = 0; //wrong
        }
        ```
    * indication that p points to a constant integer

## pointers as return values

* ```C
    int *max(int *a, int *b) {
        if (*a > *b) {
            return a;
        } else {
            return b;
        }
    }
    int i, j;
    ...
    int *p = max(&i, &j);
    ```
* can also return pointer to external variable or local static variable
* however do not return pointer to automatic local variable
    * ```C
        int *f(void) {
            int i;
            ...
            return &i;
        }
        ```
    * this is wrong because i doesn't exist after f returns, so invalid pointer
    * compilers may issue warning
* pointers can also point to array elements
    * if a is array, &a[i] is pointer to element i of a
    * ```C
        int *find_middle(int a[], int n) {
            return &a[n / 2];
        }
        ```
    * returns pointer to middle element of an array

## extra notes

* a pointer is not necessarily a memory address
    * pointers to certain types may be stored differently due to unique properties of the type
    * x86 "offsets" instead of complete addresses
        * 16 bit offset or 32 bit segment:offset pairs (2 16 bit numbers)
* ```C
    int *p = &i;
    ```
    * the * specifies the type of p (pointer), not indirection operator
* ```C
    *p = &i;
    ```
    * here, we assign the value i's address to what p points to
* display pointer using %p
* ```C
    void f(const int *p)
    ```
    * this means f can't modify the integer that p points to, but f can still change p (for example through reassignment)