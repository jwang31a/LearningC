/*
Textbook example of user IO.
*/

#include <stdio.h>
#define INCHES_PER_POUND 166 //another directive, used to clear up confusion with commonly used constants
#define RECIPROCAL_OF_PI (1.0f / 3.1415926f) //definition can be an expression, all caps convention

int volume(int length, int width, int height) {
    return length * width * height;
}

int dimensionalWeight(int volume) {
    return (volume + INCHES_PER_POUND) / INCHES_PER_POUND;
}

int main(void) {
    int length, width, height, vol, weight;
    //scanf like printf but for user input: expects a value of a specific type and puts it in a variable
    printf("Enter length of box: "); //no newlines needed because the user will provide the newline
    scanf("%d", &length); //haha funny & symbol pointers and memory addresses very fun
    printf("Enter width of box: ");
    scanf("%d", &width);
    printf("Enter height of box: ");
    scanf("%d", &height);
    vol = volume(length, width, height); //it looks like the compiler doesn't like variables and functions having the same name
    weight = dimensionalWeight(vol);
    printf("Volume (cubic inches): %d\n", vol);
    printf("Dimensional weight (pounds): %d\n", weight);
    // int a+a = 10;
    return 0;
}

/*
names of variables, functions, macros, etc are called identifiers
cannot start with digits, or contain operation characters inside them
also case sensitive, so although we can use aaa and Aaa as different variables, it's bad practice
conventions to use all lower case, connected by underscore, or java style naming
no max length of identifier
keywords have special significance
tokens: groups of characters that can't be split up without changing meaning
  - identifiers and keywords included
  - operations as well
  - punctuation marks, string literals
  - ex: printf("Height: %d\n", height); has 7 tokens
  - split up it would look like printf ( "Height: %d\n" ,  height ) ;
  - technically tokens can be crammed together with no spaces, but that's bad for readability
  - statements can be divided over any number of lines
  - space between tokens are nice for readability
  - indentation is not necessary, but helps with nesting
  - blank lines good for logical separation
no nested multiline comments
also technically compiler only remembers the first 31 chars of an identifier (63 in C99), so it may be unable to distinguish
*/