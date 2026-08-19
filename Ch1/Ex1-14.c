#include <stdio.h>
enum {a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s};

int main(void) {

    int c, fc_max, fc[26] = {0};

    fc_max = 0;
    while ((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            fc[c - 'A']++;
            fc_max = (fc[c - 'A'] > fc_max)? fc[c - 'A']: fc_max;
        }
        if (c >= 'a' && c <= 'z') {
            fc[c - 'a']++;
            fc_max = (fc[c - 'a'] > fc_max)? fc[c - 'a']: fc_max;
        }

        if (c == '\n') {

            for (int i = 0; i < 26; i++) {
                if (fc[i]) {
                    printf("%c ", i + 'A');
                    while (fc[i]-- > 0) {
                        printf("O ");
                    }
                    printf("\n");
                }
            }

            fc_max = 0;
        }
    }

    return 0 ;
}