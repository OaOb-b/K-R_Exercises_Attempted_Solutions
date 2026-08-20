#include <stdio.h>
#define IN_COMMENT 1
#define OUT_COMMENT 0
#define IN_STRING 3
#define OUT_STRING 4

/*Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest. */

int main(void) {
    int c, state;
    while ((c = getchar()) != EOF) {
        if (state != IN_COMMENT && state != IN_STRING) {}
    }

    return 0;
}