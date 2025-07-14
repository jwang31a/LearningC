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

* can use compound literals to pass to function
* `print_part((struct part) {528, "Disk drive", 10});`
    * this creates a part structure containing information, which is then passed to the function
* `part1 = (struct part) {528, "Disk drive", 10};`
    * assigns compound literal to variable
    * not a declaration containing initializer
* compound literals contain type name in parentheses, followed by values inside braces
    * type name can be preceded by struct, or typedef name
    * compound literals may fail to provide full initialization, defaults to 0 for uninitialized members

## nested arrays and structures

* structs and arrays can be combined without restriction
    * arrays can have structs as elements
    * structs can contain arrays and other structures

### nested structures

* ```C
    struct person_name {
        char first[FIRST_NAME_LEN + 1];
        char middle_initial;
        char last[LAST_NAME_LEN + 1];
    };
    ```
* this can then be used inside another structure
* ```C
    struct student {
        struct person_name name;
        int id, age;
        char sex;
    };
    ```
    * allows us to treat names as units of data
    * we can pass the structure name rather than the 3 components of a name
    * also allows easier copying

### arrays of structures

* arrays can contain structures, acting as a simple database
* `struct part inventory[100];` is like a database of 100 parts
    * you know how accessing works

### initializing array of structures

* same as initializing multidimensional array
* ```C  
    struct dialing_code {
        char *country;
        int code;
    };
    ```
    * reason why country is a pointer is because we don't want country to point to a string literal
* ```C
    const struct dialing_code country_codes[] =
    {
        {"Argentina", 54},
        {"Bangladesh", 880},
        {"Brazil", 55},
        {"Burma (Myanmar)", 95},
        {"China", 86},
        {"Colombia", 57},
        {"Congo, Dem. Rep. of", 243},
        {"Egypt", 20},
        {"Ethiopia", 251},
        {"France", 33},
        {"Germany", 49},
        {"India", 91},
        {"Indonesia", 62}, 
        {"Iran", 98},
        {"Italy", 39}, 
        {"Japan", 81},
        {"Mexico", 52}, 
        {"Nigeria", 234},
        {"Pakistan", 92}, 
        {"Philippines", 63},
        {"Poland", 48}, 
        {"Russia", 7},
        {"South Africa", 27}, 
        {"South Korea", 82},
        {"Spain", 34}, 
        {"Sudan", 249},
        {"Thailand", 66}, 
        {"Turkey", 90},
        {"Ukraine" 380}, 
        {"United Kingdom", 44},
        {"United States", 1}, 
        {"Vietnam", 84}
    };
    ```
    * c99 designated initializers allow item to have more than one designator
    * ```C
        struct part inventory[100] = {
            [0].number = 528, [0].on_hand = 10, [0].name[0] = '\0';
        }
        ```
    * selects array element 0 (part struct) and selects member within structure

### maintaining parts database

* operations supported:
    * add new part number, name, initial quantity on hand
        * error if part already in database or database full
    * given part number, print name of part and current quantity on hand
        * error if part number not in database
    * given part number, change quantity on hand
        * error if part number isn't in database
    * print table showing all info in database
        * displayed in order in which they were entered
    * terminate program execution
* codes supported:
    * i (insert)
    * s (search)
    * u (update)
    * p (print)
    * q (quit)
* limited size of database to 100 parts (inventory)
    * num_parts keeps track of currently stored parts
* program organization
    * inventory.c
    * readline.h
    * readline.c

## unions

* union consists of one or more members, can be of different types
    * but compiler only allocates enough space for the largest of the members, which overlay each other within this space
    * assigning new value to one member alters values of other members as well
* ```C
    union {
        int i;
        double d;
    } u;
    ```
    * members of structures are stored at different addresses in memory, while members of unions are stored at same address