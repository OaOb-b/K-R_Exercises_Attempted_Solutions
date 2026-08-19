#include <stdio.h>
#define IN 1
#define OUT 0

int main(void) {

    int c, nc, nw, state = OUT;

    nc = 0, nw = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;

            if (nc) printf("%d ", nw);
            while (nc--) {putchar('O');}
            putchar('\n');

            nc = 0;

            if (c == '\n') {
                nw = 0;
            }

        }else {
            if (state == OUT) {
                state = IN;
                nw++;
            }

            nc++;
        }
        
    }

    return 0;
}