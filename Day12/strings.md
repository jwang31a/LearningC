# strings

* string: series of characters
    * string constants (literals)
    * string variables can change during program execution

## string literals

* string literal: sequence of characters enclosed within double quotes
    * you know what these are

### escape sequences

* you also know what these are
* octal and hexadecimal escape sequences are also legal (but not as common)
    * octal escape ends after 3 digits or with first non octal character
        * so \1234 contains characters \123 and 4
        * \189 contains \1, 8, 9
    * hexadecimal escape isn't limited to 3 digits, so ends after first non hex character
        * Z\xfcrich has 6 characters: Z, \xfc (ü), r, i, c, h
        * \xfcber (failed attempt at über): \xfcbe and r (but most compilers don't like it due to hex escapes being limited to \x0 to xff)

### continuing string literal

* if string literal too long to fit on single line, use \ to continue
    * ```C
        printf("When you come to a form in the road, take it.\
        --Yogi Berra");
        ```
    * \ used for splicing (joining two or more lines of a program into a single line)
* this can break program structure: better way is separating string literals with whitespace
    * ```C
        printf("When you come to a fork in the road, take it. "
        "--Yogi Berra");

### how string ltierals are stored

* C treats string literals as character arrays
    * string literal length n: sets aside n + 1 bytes of memory
    * memory for the n characters, plus null character to mark the end of the string
        * null character is byte whose bits are all zero, represented by \0 escape sequence
        * do not confuse with '0' character, which has a different code
* string literals are stored as arrays, so compiler treats it as pointer of type char *

### operations on string literals

* string literal can be used wherever C allows char * pointer
    * ```C
        char *p;
        p = "abc";
        ```
    * p just points to the first character of the string
* subscripting also allowed:
    * ```C
        char ch;
        ch = "abc"[1]; //ch now assigned 'b'
        ```
    * can subscript any character from 0 to n (null character)
    * ```C
        //converts number between 0 and 15
        char digit_to_hex_char(int digit) {
            return "0123456789ABCDEF"[digit];
        }
        ```
* attempting to modify a string literal causes undefined behavior:
    * ```C
        char *p = "abc";
        *p = 'd' //NOT ALLOWED
        ```

### string literals vs character constants

* string literal containing single character != character constant
    * "a" is represented by pointer to memory location that contains a and null character
    * 'a' just contains an int
* using characters where strings are required is not allowed

## string variables

* no special string type in C; instead only 1d array of characters for strings
    * can be difficult to tell whether array is being used as a string
    * make sure properly deal with null chcaracter
* ```C
    #define STR_LEN 80
    ...
    char str[STR_LEN + 1]
    ```
    * string length defined as 80, which means we want our string to contain only 80 chars, plus 1 for the null character
    * always make the char array 1 longer than the length of the string
    * also doesn't mean the string will always be of that length, since length depends on position of null character, not the length of the array

### initializing a string variable

* `char date1[8] = "June 14";`
    * string variable can be initialized at the same time as declaration
    * "June 14" appears to be string literal, but is actually just an abbreviation for array initializer
    * equivalent to `char date1[8] = {'J', 'u', 'n', 'e', ' ', '1', '4', '\0'};`
    * if initializer is too short to fill the string variable, extra null characters added
    * initializer longer than string variable is not allowed
    * initializer same length as variable is allowed, but the compiler will not store a null character (makes it unusable as a string)
* `char date4[] = "June 14";`
    * compiler computes the length, sets aside enough memory for the characters plus a null
    * array's length cannot be changed later

### character arrays vs character pointers

* `char date[] = "June 14";` and `char *date = "June 14";` are both allowed due to relationship between pointers and arrays
    * in array version:
        * characters stored in date can be modified (like any other array)
        * date is array name
    * in pointer version:
        * date points to string literal, no modification
        * date is variable that can point to other strings during program execution
* modifiable string:
    * ```C
        #define STR_LEN 80
        char str[STR_LEN + 1], *p;
        p = str;
        ```
    * just declaring a pointer doesn't set aside enough memory for a string, so we need a char array for the memory and a pointer to point to the string
    * or make p point to dynamically allocated string
* do not use uninitialized pointer as string (duh)

## reading and writing strings

* just use printf or puts for writing
* reading is harder bc input string may be longer than string variable
    * scanf or gets

### writing strings using printf and puts

* %s conversion specification allows printf to write string
* ```C
    char str[] = "Are we having fun yet?";
    printf("%s\n", str);
    ```
    * outputs `Are we having fun yet?`
    * printf write chars in string one by one until null character (if there is no null character, it will find one eventually somewhere else in memory)
* to pring part of string: use %.ps, p is number of characters to display
    * ```C
        printf("%.6s\n", str);
        ```
    * prints `Are we`
* %ms conversion displays string in field of size m
    * string with more than m characters will be printed in full, not truncated
    * string with fewer than m characters will be right justified within field
    * left justification with - sign
* can combine m and p conversions
* `puts(str);` writes string and adds newline character

### reading strings using scanf and gets

* %s allows scanf to read string into char array
    * `scanf("%s", str);`
    * no need to put & operator bc str is treated as pointer when passed to functions
    * scanf skips whitespace first
    * probably won't read full line of input
    * scanf stops at white space (so strings read with scanf will never contain white space)
* gets function is similar, but will not skip whitespace before and will continue reading until newline (newline character discarded, replaced by null character)
* ```C
    #define SENT_LEN 80
    char sentence[SENT_LEN + 1];
    printf("Enter a sentence.\n");
    scanf("%s", sentence);
    ```
    * input of `  To C, or not to C: that is the question.`
    * scanf stores string "To" in sentence, next call of scanf will resume reading at space after "To"
    * gets(sentence) will store entire string (including leading whitespace) in sentence
* scanf and gets have no way to detect when array is full
    * they may store characters beyond end of array causing undefined behavior
    * scanf made safer by using %ns indicating max number of characters to be stored
    * gets is just unsafe, fgets is better

### reading strings char by char

* self made input functions, usually char by char
    * skip leading whitespace?
    * what end character: newline, whitespace, other?
    * do we store the end character or discard it?
    * what to do if input string too long to store? discard or leave for next input operation?
* example of `int read_line(char str[], int n);` which doesn't skip whitespace and stops reading at first newline
    * stores input into str, n is max number of chars to be read, additional characters beyond will be discarded
    * return number of characters actually stored (which may or not be useful based on circumstances)
* ```C
    int read_line(char str[], int n) {
        int ch, i = 0; //ch has int type bc getchar returns int value (although this hasn't mattered for me yet)
        while ((ch = getchar()) != '\n') {
            if (i < n) {
                str[i++] = ch;
            }
        }
        str[i] = '\0';
        return i;
    }
    ```

## accessing chars in string

* subscripting works bc strings are arraysss
* ```C
    int count_spaces(const char s[]) {
        int count = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == ' ') {
                count++;
            }
        }
        return count;
    }
    ```
    * since s is a string, instead of passing the length of the array, we can check for the null character
    * also we don't want to modify the string, so to ensure no changes happen, we use const
* ```C
    int count_spaces(const char *s) {
        int count = 0;
        for (; *s != '\0'; s++) {
            if (*s == ' ') {
                count++;
            }
        }
        return count;
    }
    ```
    * here, const prevents function from modify what s points to (the array)
    * pointer arithmetic version is probably better for strings
* can mix array operations and pointer operations, use whichever is more convenient (pointers preferred for strings)

## C string library

* default shallow copy
* ```C
    char str1[10], str2[10];
    str1 = "abc"; //wrong, this does not put the string into the array
    str2 = str1; //wrong, this does not copy
    ```
    * `char str[10] = "abc";` is allowed
    * `if (str1 == str2) ...` compares the pointers, not the contents of the array (and since the arrays have different addresses, this is false)
* `#include <string.h>` for string functions
    * string parameters have type char *, so char arrays, variable of type char *, or string literal allowed
    * some functions may not have const parameters, so string literals may not be suitable

### strcpy

* `char *strcpy(char *s1, const char *s2);`
    * copies string s2 into s1 (all chars plus the first null char), returns s1
    * ```C
        strcpy(str2, "abcd"); //str2 contains "abcd"
        strcpy(str1, str2); //str1 contains "abcd" as well
        ```
    * return value is usually discarded, but can be useful when chaining functions
    * ```C
        strcpy(str1, strcpy(str2, "abcd")); //str1 and str2 contain "abcd"
        ```
    * no way for strcpy to check that str2 will fit in str1
* strncpy is safer: `strncpy(str1, str2, sizeof(str1))`
    * but this doesn't copy the terminating character if str2's size is greater than or equal to size of str1
    * ```C
        strncpy(str1, str2, sizeof(str1) - 1);
        str1[sizeof(str1) - 1] = '\0';
        ```
    * guarantees str1 is null terminated, even if strncpy doesn't copy null char

### strlen

* `size_t strlen(const char *s);`
* size_t is a typedef, represing one of C's uint types, but can usually be treated as an int
* ```C
    int len;
    len = strlen("abc"); //3
    len = strlen(""); //0
    strcpy(str1, "abc");
    len = strlen(str1); //3
    ```
    * strlen doesn't measure the length of the array holding the string, but the length of the string stored

### strcat

* `char *strcat(char *s1, const char *s2);`
* appends s2 to end of s1, returns s1
* ```C
    strcpy(str1, "abc");
    strcat(str1, "def"); //str1 contains "abcdef"
    ```
* ```C
    strcpy(str1, "abc");
    strcpy(str2, "def");
    strcat(str1, strcat(str2, "ghi")); //str1 contains "abcdefghi"
    ```
* undefined if str1 isn't long enough to contain additional characters from str2, may write past end of array
* `strncat(str1, str2, sizeof(str1) - strlen(str1) - 1);`
    * this makes sure that only the empty spaces in str1 get additional characters, except the last one which is reserved for the null char (auto terminates by strncat)

### strcmp (string comparison)

* `int strcmp(const char *s1, const char *s2);`
    * compares s1 and s2, returning negative if s1 < s2, 0 if equal, or positive if s1 > s2
    * lexicographic ordering
    * A-z, a-z, 0-9 have consecutive codes
    * uppercase are less than lowercase (uppercase 65-90, lowercase 97 - 122)
    * digits less than letters (48 - 57)
    * spaces less than all printing characters (value 32)

## string idioms

* cannot write function with the same name as a standard library function (all names beginning with str and lowercase letter are reserved to allow future functions to be added to string.h header)

### searching for end of string

* ```C
    size_t strlen(const char *s) {
        size_t n;
        for (n = 0; *s != '\0'; s++) {
            n++;
        }
        return n;
    }
    ```
    * basic, but can be condensed
* ```C
    size_t strlen(const char *s) {
        size_t n = 0;
        while (*s++) { //because null char is 0, this will break when s points to a null char
            n++;
        }
        return n;
    }
    ```
    * condensed, but likely isn't actually faster
* ```C
    size_t strlen(const char *s) {
        const char *p = s;
        while (*s) {
            s++;
        }
        return s - p;
    }
    ```
    * computes the position of the null character and subtracts the position of first character (no need to increment n)
* ```C
    while (*s) {
        s++;
    }
    ```
    vs
    `while (*s++);`:
    * both search for the null character, but first one points s to null, while second one points s past null character
    * okay supposedly they're slightly different but in my testing i'm not so sure

### copying a string

* ```C
    char *strcat(char *s1, const char *s2) {
        char *p = s1;
        while (*p != '\0') { //locate end of s1
            p++;
        }
        while (*s2 != '\0') {//append chars from s2 to end of s1
            *p = *s2;
            p++;
            s2++;
        }
        *p = '\0';
        return s1;
    }
    ```
    * can be condensed
* ```C
    char *strcat(char *s1, const char *s2) {
        char *p = s1;
        while (*p) {
            p++;
        }
        while (*p++ = *s2++); //main idiom, just ordinary assignment
        return s1;
    }
    ```

## arrays of strings

* ```C
    char planets[][8] = {
        "Mercury", "Venus", "Earth", "Mars",
        "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"
    };
    ```
    * number of rows is implied and inferred by compiler, but the number of columns must be supplied
    * in memory, this will look like a matrix of characters
    * for shorter planet names, there will be a lot of empty characters after the name, leading to memory inefficiency
* solution is ragged array, where rows can have different lengths, but C doesn't have one
* ```C
    char *planets[] = {
        "Mercury", "Venus", "Earth", "Mars",
        "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"
    };
    ```
    * this simulates a ragged array by having an array of pointers that point to those strings

### command line arguments

* `ls` displays names of files, `ls -l` displays longer, detailed version, `ls -l file` displays detailed information about a file
* we can obtain access to command line arguments (program parameters), define main
* ```C
    int main(int argc, char *argv[]) {
        ...
    }
    ```
    * argc is argument count, number of command line arguments (includes name of program)
    * argv is argument vector, array of pointers to command line arguments stored in string form
        * argv[0] is name of program, everything else is remaining command line arguents
        * also has argv[argc], which is null pointer (points to nothing)
        * macro NULL represents null pointer
* `ls - l remind.c`: argc = 3
    * argv[0] points to string containing program name, can be empty string if program name not available
    * argv[1] points to "-l"
    * argv[2] points to "remind.c"
    * argv[3] null pointer
* ```C
    int i;
    for (i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    ```
    * evaluates command line arguments, prints one per line
* ```C
    char **P;
    for (p = &argv[1]; *p != NULL; p++) {
        printf("%s\n", *p);
    }
    ```
    * p is a pointer to a pointer to a character
    * argv[1] is a pointer to a character, &argv[1] is a pointer to a pointer

## q&a notes

* string literals must be at least 509 chars long in C89, at least 4095 in C99
* string literals are not necessarily constant, can be modified through pointers
* something such as über cannot be written as \xfcber
    * instead, create 2 string literals "\xfc" "ber" and let the compiler join them
* compilers may store single copies of identical string literals, so modifying one will modify all copies of it
    * string literals may also be read only
* not all char arrays are strings, so not all char arrays should include null characters
    * on the other hand, it's probably best for strings to have a null character
* printf and scanf expect first argument to have type char *, so you can actually replace with string variable
    * ```C
        char fmt[] = "%d\n";
        int i;
        ...
        printf(fmt, i);
        ```
* can do `printf(str);`, but if str contains % that's not good
* ```C
    int read_line(char str[], int n) {
        int ch, i = 0;
        while ((ch = getchar()) != '\n' && ch != EOF) {
            if (i < n) {
                str[i++] = ch;
            }
        }
        str[i] = '\0'
        return i;
    }
    ```
    * this small modification to read_line detects whether getchar fails to read a character
    * if getchar can't read a character, it returns EOF (end of file) of type int
* traditional strcmp implementation
    * ```C
        int strcmp(char *s, char *t) {
            int i;
            for (i = 0; s[i] == t[i]; i++) {
                if (s[i] == '\0') {
                    return 0;
                }
            }
            return s[i] - t[i];
        }
        ```
    * return value is the difference between first mismatched characters
* argv can be declared as **argv instead of *argv[], since *a is a[]