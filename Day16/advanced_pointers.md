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

## deallocating storage

* memory allocation functions obtain memory from the heap
    * calling them too foten can exhaust heap, causing null pointer returns
* program may also allocate memory and lose track of them, wasting space (garbage and memory leak)
    * ```C
        p = malloc(...);
        q = malloc(...);
        p = q;
        ```
    * this creates a situation where p used to point to a memory block, but nothing points to it now
    * some languages provide garbage collector to automatically locate and recycle garbage, but C doesn't have this
    * must manually free memory (free function)

### free function

* \<stdlib.h\> prototype: `void free(void *ptr);`
* just pass a pointer to a memory block we no longer need
    * ```C
        p = malloc(...);
        q = malloc(...);
        free(p);
        p = q;
        ```
    * argument to free must be pointer returned by memory allocation function (or null pointer which has no effect)
    * do not pass pointer to any other object

### dangling pointer problem

* free function leads to new problem: dangling pointers
    * `free(p)` deallocates memory block that p points to, but doesn't change p itself
    * further modifications of p will cause problems because the program no longer controls that memory
    * multiple pointers may point to the same block, causing difficulties in spotting the issue

## linked lists

* dynamic storage allocation useful for linked data structures
* linked lists yippee
    * you know how they work mr. data structures and algorithms ta

### declaring node type

* we need a structure representing a single node in the list (assume that data type is integer)
    * ```C
        struct node {
            int value; //data in node
            struct node *next; //pointer to next node
        };
        ```
    * when a structure has member that points to same kind of structure, we have to use a structure tag
        * typedef does not work here
* we need to keep track of where the list begins
    * ```C
        struct node *first = NULL;
        ```
    * this just means the list is empty initially

### creating node

* steps for creating a node:
    1) allocate memory for node
    2) store data in node
    3) insert node into list
* when creating new node, we need variable that points to node temporarily until insertion
    * ```C
        struct node *new_node;
        new_node = malloc(sizeof(struct node));
        ```
    * now new_node points to block of memory just large enough to hold node structure
    * make sure to get the size of the structure, not the pointer
* next, we store data into new node
    * ```C
        (*new_node).value = 10;
        ```
    * so now the value has been set to 10, but next is still null

### right arrow selection operator (->)

* accessing member of structure using pointer is so common that we use the right arrow seledction operator ->
    * ```C
        new_node->value = 10;
        ```
    * this does the same thing as indirection then selection
    * -> produces lvalue, so we can use it wherever ordinary variable would be allowed
    * ```C
        scanf("%d", &new_node->value);
        ```
    * the & operator is still necessary though because we want the address of this member, not the int value

### inserting node at beginning of linked list

* nodes can be added anywhere in a linked list easily
* ```C
    new_node->next first;
    first = new_node;
    ```
    * both new_node and first are pointers
    * new_node already has data, so we set it's next to first
    * then we set set first to what new_node points to (they point to the same node now, the first node)
    * any further adding like this will insert nodes before the old first
* ```C
    struct node *add_to_list(struct node *list, int n) {
        struct node *new_node;
        new_node = malloc(sizeof(struct node));
        if (new_node == NULL) {
            printf("Error: malloc failed in add_to_list\n");
            exit(EXIT_FAILURE);
        }
        new_node->value = n;
        new_node->next = list;
        return new_node;
    }
    ```
    * this does not modify the list pointer, it only returns a pointer to the new first node
    * therefore, we need to store this pointer into first each time we call add_to_list
    * ```C
        first = add_to_list(first, 10);
        first = add_to_list(first, 20);
        ```
* sample function using add_to_list function
    * ```C
        struct node *read_numbers(void) {
            struct node *first = NULL;
            int n;
            printf("Enter a series of integers (0 to terminate): ");
            for (;;) {
                scanf("%d", &n);
                if (n == 0) {
                    return first;
                }
                first = add_to_list(first, n);
            }
        }
        ```
    * since singly linked lists are first in last out, the numbers will be in reverse order inside the list

### searching linked list

* idiom for searching:
    * ```C
        for (p = first; p != NULL; p = p->next) {
            ...
        }
        ```
* search list for integer n: if found, return pointer to node containing n, otherwise null pointer
    * ```C
        struct node *search_list(struct node *list, int n) {
            struct node *p;
            for (p = list; p != NULL; p = p->next) {
                if (p->value == n) {
                    return p;
                }
            }
            return NULL;
        }
        ```
* alternative search without a p, using list to keep track of the current node (because list is a copy of the original, we can change it safely)
    * ```C=
        struct node *search_list(struct node *list, int n) {
            for (; list != NULL; list = list->next) {
                if (list->value == n) {
                    return list;
                }
            }
            return NULL;
        }
        ```
* even simpler is doing the comparison inside the loop test (although at this point it's getting difficult to read)
    * ```C
        struct node *search_list(struct node *list, int n) {
            for (; list != NULL && list->value != n; list = list->next);
            return list;
        }
        ```
* this might be the most readable and simple version:
    * ```C
        struct node *search_list(struct node *list, int n) {
            while (list != NULL & list-> value != n) {
                list = list->next;
            }
            return list;
        }
        ```

### deleting node from linked list

* advantage of storing data in linked list is easy deletion of data (without shifting)
    * all we need to do is locate node to be stored
    * alter previous node so it bypasses deleted node
    * (CRUCIAL) free the space occupied by deleted node
* trailing pointer technique: have 2 pointers, one to current node, the other to the pointer right before it
    * ```C
        for (cur = list, prev = NULL; cur != NULL && cur->value != n; prev = cur; cur = cur->next);
        ```
    * if we reach a situation where cur's data is what we're looking for, we bypass it using the prev pointer
    * then we have to free whatever we found
    * ```C
        struct node *delete_from_list(struct node *list, int n) {
            struct node *cur, *prev;
            for (cur = list, prev = NULL; cur != NULL && cur->value != n; prev = cur, cur = cur->next);
            if (curr == NULL) {
                return list;
            }
            if (prev = NULL) { //this block is 
                list = list->next;
            } else {
                prev-> = cur->next;
            }
            free(cur);
            return list;
        }
        ```
* or the dsa way that i learned which uses 1 pointer only

### ordered lists

* when nodes of list are kept in order, sorted by data inside nodes, the list is ordered
    * inserting node into ordered list is more difficult, but searching is fast and we can insert after we've found a good place for the node

### maintaining parts database

* revision of the parts database so that we store database inside a linked list instead of an array
    * we don't have a preset limit on how many parts we can store
    * and we can keep the database stored by part number using the properties of a linked list and nodes
* part structure will be a linked node containing a pointer to the next node in the linked list
    * inventory will be pointer to the first node in the list
    * ```C
        struct part {
            int number;
            char name[NAME_LEN + 1];
            int on_hand;
            struct part *next;
        };
        struct part *inventory = NULL; //points to first part, temporarily null
        ```
* find_part will be a linked list search, insert will contain a linked list search
    * ```C
        for (p = inventory; p != NULL && number > p->number; p = p->next);
        ```
    * this will look for the first node part number that is less than the one we are inserting
    * if p becomes NULL in the case that we reach the end of the linked list, then we need to deal with that accordingly
        * ```C
            if (p != NULL && number == p->number) {
                return p;
            }
            ```
* insert will use a loop similar to the other loop:
    * ```C
        for (cur = inventory, prev = NULL; cur != NULL && new_node->number > cur-> member; prev = cur, cur = cur->next)
        ```
    * relies on 2 pointers like before
    * after loop termination, inesrt will check whether cur isn't NULL and new_node->number equals cur->number
        * if so, part is already in list (no insertion)
        * otherwise, insert new node between prev and cur (this works for the end as well)

## pointers to pointers

* pointer to a pointer exists: for example in an earlier chapter, we had an array of char pointers, so a pointer to one of the array elements itself has a type char **
* pointers to pointers are common in linked data structures
    * when argument to function is pointer variable, we may want the function the modify variable by making it point somewhere else, which uses pointers to pointers
* i.e we want to assign new_node to list instead of returning new_node in add_to_list
    * ```C
        struct node *add_to_list(struct node *list, int n) {
            struct node *new_node;
            new_node = malloc(sizeof(struct node));
            if (new_node == NULL) {
                printf("Error: malloc failed in add_to_list\n");
                exit(EXIT_FAILURE);
            }
            new_node->value = n;
            new_node->next = list;
            return new_node;
        }
        ```
    * suppose we modify function so that it assigns new_node to list instead of returning new_node
        * `list = new_node;`
    * because pointers are passed by value, not reference, changing what list is doesn't actually change what first points to outside of this function
* instead, we need a pointer to a pointer: in this case, passing add_to_list a pointer to first
    * ```C
        void add_to_list(struct node **list, int n) {
            struct node *new_node;
            new_node = malloc(sizeof(struct node));
            if (new_node == NULL) {
                printf("Error: malloc failed in add_to_list\n");
                exit(EXIT_FAILURE);
            }
            new_node->value = n;
            new_node->next = *list;
            *list = new_node;
        }
        ```
    * so, when we call this version of add_to_list, the first argument is the address of first
        * `add_to_list(&first, 10);`
        * assigning new_node to *list will modify first because first points to a pointer that points to the first node
        * *list is used as an alias for first

## pointers to functions

* pointers can point to data, like variables, array elements, dynamically allocated blocks of memory
* pointers in C can also point to functions because functions also occupy memory locations and have addresses

### function pointers as arguments

* for example we want to write an integrate function that integrates a mathematical function
    * to generalize the integrate function as much as possible, so we'd like to pass a function f to integrate
    * prototype `double integrate(double (*f)(double), double a, double b);`
    * (*f) means f is a pointer to a function, not a function that returns pointer
    * can also declare as `double integrate(double f(double), double a, double b);`
    * example call: `result = integrate(sin, 0.0, PI / 2);`
        * here, when the function name isn't followed by parentheses, C compiler produces pointer to function
        * we are not calling sin, we are passing a pointer to sin
    * within integrate, we call function that f points to using `y = (*f)(x);`
        * technically we can do `f(x)` as well, but that obscures the fact that f is a pointer to a function

### qsort function

* qsort function can sort any array, based on criteria we choose
    * since it can contain things like unions or structures, we need to define a function to determine which of two elements is smaller
    * we need a comparison function: when given two pointers p and q to array elements, function must return integer that is negative if *p is less than *q, 0 if equal, positive if *p greater than *q
    * pretty much the compareTo function from java
* ```C
    void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
    ```
    * base points to first element in array (can point to an unsorted portion if some of the array is sorted)
        * can just be the name of the array
    * nmemb is the number of elements to be sorted (not necessarily number of elements in array)
    * size is the size of each array element in bytes
    * compar is a pointer to the commparison function
    * qsort sorts array in ascending order, using the comparison function whenever it needs
* to sort inventory array in earlier section, call:
    * `qsort(inventory, num_parts, sizeof(struct part), compare_parts);`
    * num_parts is only the number of parts actually inserted, not the maximum number of parts the array can hold
* comparison function:
    * qsort requires parameter has type void *, but we can't access members of part structure through void * pointer
    * comparison function must assign parameters p and q to variables of type struct part * to convert types
    * ```C
        int compare_parts(const void *p, const void *q) {
            const struct part *p1 = p;
            const struct part *q1 = q;
            if (p1->number < q1->number) {
                return -1;
            } else if (p1->number == q1->number) {
                return 0;
            } else {
                return 1;
            }
        }
        ```
    * const is necessary to avoid warning, also we don't want to modify whatever the pointers point to
    * ```C
        int compare_parts(*const void *p, const void *q) {
            if (((struct part *) p)->number < ((struct part *) q)->number) {
                return -1;
            } else if (((struct part *) p)->number == ((struct part *) q)->number) {
                return 0;
            } else {
                return 1;
            }
        }
        ```
    * parentheses around ((struct part *) p) are necessary because we need to cast p to the right type and then get number from it
    * can be even more consise:
    * ```C
        int compare_parts(const void *p, const void *q) {
            return ((struct part *) p)->number - ((struct part *) q)->number;
        }
        ```
    * subtracting two integers can be dangerous because of overflow, but part numbers are assumed to be positive
* to compare using part name instead of part number, we could write a different version of the comparison function:
    * ```C
        int compare_parts(const void *p, const void *q) {
            return strcmp(((struct part *) p)->name, ((struct part *) q)->name);
        }
        ```
    * strcmp also returns a negative, 0, or positive result

### other uses of function pointers

* pointers to functions are just like pointers to data, so we can store function pointers in variables or use them as elements of an array or members of a struct or union
* `void (*pf)(int);`
    * pf points to any function with an int parameter and return type of void
    * if `f` is a function, `pf` can point to `f` by: `pf = f;`
    * no need for `&` before `f`
    * to call `f` using `pf`, do `(*pf)(i);` or `pf(i);`
* arrays with function pointer elements are surprisingly useful
    * for example, we can store all possible commands for a program in an array and subscript as needed to run the right function
    * similarly, we could use a switch statement, but function pointer elements allow more flexibility
        * elements can be changed during execution

### tabulating the trigonometric functions (program)

* 