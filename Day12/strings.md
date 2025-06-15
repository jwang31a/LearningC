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