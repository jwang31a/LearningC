# structures, unions, enumerations

* 3 new types: structures, unions, enumerations
    * structure is collection of values (members), possibly of different types
    * union similar to structure, except members share same storage and can store one member at a time, but not all members simultaneously
    * enumeration is integer type whose values are named by programmer
* structs the most important by far

## structs

* array is a data structure
    * all elements of array have same type
    * to select array element, specify position as integer subscript
* structure properties:
    * elements (members) not required to have same type
    * members of structure have names, so to select member, specify name, not position

### declaring structure variables

* structure makes sense for storing a collection of related data items
* ```C
    struct {
        int number;
        char name[NAME_LEN + 1];
        int on_hand;
    } part1, part2;
    ```
    * this structure holds 3 members: number, name, and on_hand
    * struct {...} specifies a type
    * part1 and part2 are variables of this struct type
    * members of structure stored sequentially in memory in the order in which they're declared, so 4 bytes for number, however many bytes for the string, and 4 bytes for the int
* each structure represents new scope, so names declared in that scope won't conflict with other names in program
    * (separate name space for each structure)

### initializing structure variables

* struct variable can be initialized at declaration time
    * ```C
        struct {
            int number;
            char name[NAME_LEN + 1];
            int on_hand;
        } part1 = {528, "Disk drive", 10},
          part2 = {914, "Printer cable", 5};
        ```
* values in initializer must appear in same order as members of structure
    * similar to array initializer rules
    * expressions used must be constant (not necessarily in C99)
    * can have fewer members than structure it's initializing, leftover members given placeholder values of 0

### designated initializers

* `{528, "Disk drive", 10}` can also be written as `{.number = 528, .name = "Disk drive", .on_hand = 10}`
    * combination of period and member name is called designator
    * helps with making sure all members get the correct value
    * also doesn't have to be in order, so order of members can be changed in the future without affecting designated initializers
* not all values listed in designated initializer need to be prefixed
    * `{.number = 528, "Disk drive", .on_hand = 10}`
    * the string is assumed to initialize the member after number
    * any unaccounted members given value 0

### operations on structures

* selecting a member is done through name, not position
    * name of structure, then period, then member name
    * ```C
        printf("Part number: %d\n", part1.number);
        printf("Part name: %s\n", part1.name);
        printf("Quantity on hand: %d\n", part1.on_hand);
        ```
* members of structure are also lvalues, so we can assign or increment/decrement them to change values
    * ```C
        part1.number = 258;
        part1.on_hand++;
        ```
    * the period operator has same precedence as postfix ++ and --, so it takes precedence over nearly all operators
    * `&part1.on_hand` gives the memory address of on_hand in part1
* assignment can copy each member
    * `part2 = part1;` actually copies things like arrays
    * very useful for creating dummy strucures containing things to be copied
    * ```C
        struct {int a[10];} a1, a2;
        a1 = a2; //legal as both are structures
        ```
* the = operator can only be used with structures of compatible types
    * structures declared using the same "structure tag" or the same type name are compatible
* no operations on entire structures so comparison can't use == or !=

## structure types

* we've only covered declaring structure variables, but not naming them
    * ```C
        struct {
            int number;
            char name[NAME_LEN + 1];
            int on_hand;
        } part1;

        struct {
            int number;
            char name[NAME_LEN + 1];
            int on_hand;
        } part2;
        ```
    * part1 and part2 are technically not compatible
* use structure tag or typedef to define type name

### declaring structure tag

* structure tag: name used to identify particular kind of structure
    * ```C
        struct part {
            int number;
            char name[NAME_LEN + 1];
            int on_hand;
        }; //terminates declaration with ;

        struct part part1, part2; //struct is necessary because part isn't type name
        ```
    * structure tags don't conflict with other names in program (although it's confusing)
* can combine structure tag with declaration
    * ```C
        struct part {
            int number;
            char name[NAME_LEN + 1];
            int on_hand;
        } part1, part2;
        ```
    * all structures declared to have type struct part are compatible with one another
    * ```C
        struct part part1 = {528, "Disk drive", 10};
        struct part part2;
        part2 = part1; //legal as both have same type
        ```

### defining structure type

* typedef for declaring type name
    * ```C
        typedef struct {
            int number;
            char name[NAME_LEN + 1];
            int on_hand;
        } Part;
        ```
    * type name has to come after the struct {...}
    * just use type `Part`, not `struct Part`
* structure tag mandatory when structure used in linked list

### structures as arguments and return values

* ```C
    void print_part(struct part p) {
        printf("Part number: %d\n", p.number);
        printf("Part name: %s\n", p.name);
        printf("Quantity on hand: %d\n", p.on_hand);
    }

    print_part(part1);
    ```
* ```C
    struct part build_part(int number, const char *name, int on_hand) {
        struct part p;
        p.number = number;
        strcpy(p.name, name);
        p.on_hand = on_hand;
        return p;
    }

    part1 = build_part(528, "Disk drive", 10);
    ```
* passing structure to funciton and returning structure from function requires making copy of all members in structure, leading to higher overhead
    * pass pointer to structure instead or return pointer to structure
* \<stdio.h\> defines type named FILE, typically structure
    * FILE structure stores information about state of open file and must be unique in program
    * functions in \<stdio.h\> that open file returns pointer to FILE structure, every function that performs operation on open file requires FILE pointer as argument
* initializing struct variable inside function is allowed due to automatic storage duration
    * ```C
        void f(struct part part1) {
            struct part part2 = part1;
            ...
        }
        ```
    * part2 is local to the function because it's not static

### c99 compound literals