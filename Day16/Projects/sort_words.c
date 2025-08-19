#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define WORD_LEN 20

int compare_words(const void *w1, const void *w2) { //takes input as words
    return strcmp(*(char **)w1, *(char **)w2); //but to treat these as strings, we need to cast them
    //simply casting to char * will not work because we are comparing addresses
    //then using *(char *) won't work either because that points to a char
    //so we need *(char **) for this to work
}

void *my_malloc(size_t bytes) { //this is our own allocation function because we may need to handle the case where reallocation fails
    void *p;
    if ((p = malloc(bytes)) == NULL) {
        exit(EXIT_FAILURE);
    }
    return p;
}

int main(void) {
    char **words = NULL; //a dynamically allocated array of pointers to strings (words)
    char *word = NULL; //storage for our word
    int i, size = 1, num_words = 0;
    words = (char **) my_malloc((size_t)(sizeof(char *))); //initialize words to the size of 1 char *, enough for 1 string (word)
    for (i = 0; ; i++) { //this will be true until we break out, i just counts
        word = (char *) my_malloc((size_t)WORD_LEN + 1); //allocate space for a word using macro
        printf("Enter word: ");
        fgets(word, WORD_LEN + 1, stdin); //fgets requires a char * pointer (string), the bytes, and input stream (usually stdin)
        if (word[0] == '\n') { //deals with enter key case
            break;
        } else if (word[strlen(word) - 1] == '\n') { //converts ending enter press into a null character to make it work with strings
            word[strlen(word) - 1] = '\0';
        }
        *(words + i) = word; //put word in the next empty spot
        num_words++; //now we have more words
        if (size == num_words) { //dynamically reallocates word storage like in arraylist
            if ((words = (char **) realloc(words, (size_t)(sizeof(char *) * (size *= 2)))) == NULL) {
                printf("Reallocation failed.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    qsort(words, num_words, sizeof(char *), compare_words); //passing compare words function to quicksort, which takes in an array, the number of elements we want to sort, the size of the elements, and our comparison
    printf("\nIn sorted order: ");
    for (i = 0; i < num_words; i++) {
        printf("%s ", *(words + i));
    }
    printf("\n");
    return 0;
}