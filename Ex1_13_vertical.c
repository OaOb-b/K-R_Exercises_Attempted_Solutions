#include <stdio.h>
#define IN 1
#define OUT 0
#define LIMIT 1000

int main(void) {

    int c, nw, nc_max, state = OUT;
    int nc[LIMIT] = {0};

    nc_max = 0, nw = 0;
    while ((c = getchar()) != EOF && nw <= LIMIT) {
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;

            if (c == '\n') {
                for (int i = 0; i < nw; i++) {
                    printf("%d ", i+1);
                }
                printf("\n");
                
                for (int i = 0; i < nc_max; i++) {
                    for (int j = 0; j < nw; j++) {
                        if (nc[j]-- > 0) {
                            printf("O ");
                        }else{
                            printf("  ");
                        }
                    }
                    printf("\n");
                }

                nc_max = 0, nw = 0;             
            }

        }else {
            if (state == OUT) {
                state = IN;
                nw++;
            }

            nc[nw-1]++;
            nc_max = (nc[nw-1] > nc_max)? nc[nw-1] : nc_max;

        }
    }

    return 0;
}