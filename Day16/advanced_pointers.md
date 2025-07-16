# chapter 17: advanced uses of pointers

* dynamic storage allocation and pointers to functions in this chapter
* dynamic storage allocation:
    * program can obtain blocks of memory as needed during execution
    * more flexibility (like dynamically allocated strings or arrays in general)
    * also storage deallocation when no longer needed
    * very useful for other data structures like LL, trees
    * also pointer to a pointer is important
* pointers to functions 
    * some library functions expect function pointers as arguments like qsort
    * c99 restricted pointers and flexible array members
        * advanced, but still interesting

## dynamic storage allocation

* data structures normally fixed size, but can be a problem because we can't do anything when the structure is full
* C supports dynamic storage allocation to address this problem

### memory allocation functions

* all memory allocation functions under \<stdlib.h\> header
    * malloc: allocates a block of memory but doesn't initialize it
    * calloc: allocates block of memory and clears it
    * realloc: resizes previously allocated block of memory
* malloc most used, more efficient than calloc
* when we call memory allocation function, function doesn't know what we're storing in block, so returns pointer of type void *
    * void * is generic pointer, just a memory address

### null pointers

* when memory allocation function called, possibility that block of memory large enough can't be found
    * function returns null pointer (pointer to nothing) that can be distinguished from valid pointers
    * we must test to see if we got a null pointer (this is our responsibility to test)
    * null pointer represented by macro named NULL
    * ```C
        p = malloc(10000);
        if (p == NULL) {
            //allocation failed, take appropriate action
        }
        ```
* simplification into:
    * ```C
        if ((p = malloc(10000)) == NULL) {
            //allocation failed, take appropriate action
        }
        ```
* NULL macro defined in locale.h, stddef.h, stdio.h, stdlib.h, string.h, time.h (and c99 wchar.h)
    * as long as any of these headers included, compiler will recognize NULL
* pointers test true/false like numbers
    * all non null pointers test true, only null pointers are false
    * `if (p == NULL)` equivalent to `if (!p)`
    * `if (p != NULL)` equivalent to `if (p)`
    * stylistic choice to compare with NULL

## dynamically allocated strings

* by allocating strings dynamically, we can postpone decision until program runs

### using malloc to allocate memory for string

* malloc prototype: `void *malloc(size_t size);`
    * malloc allocates block of size bytes and returns pointer to it
    * size_t is unsigned integer type, but for normal memory blocks, treat size as ordinary integer
* malloc for string: char uses 1 byte, and we need an extra byte for the null character
    * `p = malloc(n + 1);`
    * p is a char * variable (generic pointer returned converted when assignment performed, no cast necessary)
* memory using malloc isn't cleared or initialized, so p points to uninitialized array of n + 1 characters
* can use `strcpy(p, "abc");` to put a, b, c, and \0 in this array

### using dynamic storage allocation in string functions

* can use dynamic storage allocation to write functions to return pointer to new string that didn't exist before function call
    * i.e. concatenating 2 strings without changing either one (not strcat b/c that modifies one string)
    * ```C
        char *concat(const char *s1, const char *s2) {
            char *result;
            result = malloc(strlen(s1) + strlen(s2) + 1);
            if (result = NULL) {
                printf("Error: malloc failed in concat\n");
                exit(EXIT_FAILURE);
            }
            strcpy(result, s1);
            strcpy(result, s2);
            return result;
        }
        ```
    * so if malloc returns null pointer, concat prints error message and terminates, but sometimes we need to recover and continue running
    * ```C
        p = concat("abc", "def");
        ```
        * after this, p points to "abcdef", 7 characters
* MAKE SURE TO FREE THE MEMORY WHEN IT'S NO LONGER NEEDED
    * call free to release the space that the string occupies otherwise the program may run out of memory

### arrays of dynamically allocated strings

* storing rows in 2d array of characters can waste space, so we can set up an array of pointers to string literals
    * instead, we can have pointers to dynamically allocated strings

### printing one-month reminder list (revisited)

* rewrite remind.c with dynamically allocated strings
    * each reminder string stored in 2d array of chars, each row containing one string
    * strcmp to compare and find where the string belongs
    * strcpy to move strings down one position
    * strcat to append reminder to day
* remind2.c new version:
    * 1d array where elements are pointers to dynamically allocated strings
    * more efficient storing because we can allocate the exact number of characters
    * no strcpy needed because we just move pointers to strings
    * actually very few changes to the program necessary

## dynamically allocated arrays

* dynamically allocated arrays are cool as well
* arrays and pointers have close relationship, so dynamically allocated arrays are just as easy to use as ordinary array
* calloc can sometimes be used, because it initializes memory allocated
    * realloc can make array grow or shrink as needed

### using malloc to allocate storage for array

* we can use malloc to allocate space for array like with strings, but the elements may not necessarily be one byte
    * sizeof operator to calculate amount of space required for each element
* program that needs array of n integers, n computed during execution of program
    * ```C
        int *a;
        //then n gets calculated
        a = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            a[i] = 0;
        }
        ```
    * the sizeof is necessary because the size of a type may not be consistent between compilers and computers
    * once a points to a dynamically allocated block of memory, we can treat a as an array name

### calloc

* calloc can be a better alternative to malloc
* calloc prototype:
    * `void *calloc(size_t nmemb, size_t size);`
    * calloc allocates space for array with nmemb elements, each of which is size bytes long, returns null pointer if requested space not available
    * after allocating memory, calloc initializes by setting all bits to 0
    * `a = calloc(n, sizeof(int));`
* the property of clearing memory can be useful, so calloc can be better for allocating space for objects other than arrays like structs
    * ```C
        struct point {
            int x, y;
        } *p;
        p = calloc(1, sizeof(struct point));
        ```
    * p then points to structure whose x and y members set to 0

### realloc function

* the memory we've already allocateed may be insufficient or inefficiently used, so realloc resizes array
    * `void *realloc(void *ptr, size_t size);`
    * ptr must point to memory block from previous call of malloc, calloc, or realloc
    * size represents new size of block, which can be larger or smaller than original size
    * ptr usually points to memory used in array, although no requirement that it does
* standard rules for realloc:
    * when expanding memory block, realloc doesn't initialize bytes added
    * if realloc can't enlarge memory block as requested, returns null pointer and old memory block is unchanged
    * if realloc called with null pointer as first argument, behaves like malloc
    * if realloc called with 0 as second argument, frees memory
* no specifics on implementation, but reasonable assumption of efficiency
    * when reducing size, realloc shrinks block "in place" without moving data
    * when attempting to expand memory block, it will try to expand without moving data
        * although if unable to enlarge block, realloc will allocate new block elsewhere and copy contents
        * make sure to update all pointers to memory block because realloc may move block elsewhere