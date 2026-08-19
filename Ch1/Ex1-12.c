#include <stdio.h>
#define IN 1
#define OUT 0

int main(void) {

    int c, state;

    while ((c = getchar()) != EOF) {
        if (c == '\t' || c == '\n' || c == ' ') {
            state = OUT;
        }else if (state == OUT){
            putchar('\n');
            state = IN;
        }

        putchar(c);
    }

    return 0;
}