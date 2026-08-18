#include <stdio.h>

int main(void) {

    int c, in_blanks;

    in_blanks = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (in_blanks) 
                continue;
            in_blanks = 1;
        }else {
            in_blanks = 0;
        }
        putchar(c);
    }

    return 0;
}