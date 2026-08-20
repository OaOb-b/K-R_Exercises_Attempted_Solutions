#include <stdio.h>
#define MAXLINE 1000
#define IN 1
#define OUT 0

/*Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
When either a tab or a single blank would suffice to reach a tab stop, which should be given
preference? */

int getline(char [], int);
char *entab(char [], char [], int, int);

int main(void) {
    
    int len;
    char line[MAXLINE], entabbed[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        printf("%s", entab(line, entabbed, 8, MAXLINE));
    }

    return 0;
}

int getline(char s[], int limit) {
    int i, c;

    i = 0;
    while ((c = getchar()) != EOF && c != '\n' && i < limit-1) {
        s[i++] = c;
    }

    if (c == '\n') {
        s[i++] = '\n';
    }

    s[i] = '\0';

    return i;
}

char *entab(char s[], char e[], int n, int limit) {
    int i, j, cp;
    int state, nt, nb, temp;

    state = OUT, nt = 0, nb = 0;
    for (i = 0, j = 0, cp = 0; s[i] != '\0' && j < limit-1; i++) {
        if (s[i] == ' ') {
            state = IN;
            nb++;

        }else {

            if (state == IN) {
                
                temp = nb;
                
                nt = (nb - n + cp%n >= 0)? (1 + (nb - n + cp%n)/n): 0;
                nb = (nb - n + cp%n >= 0)? (nb - n + cp%n - n*(nt-1)): nb;

                while (nt > 0 && j < limit - 1) {
                    e[j++] = '\t';
                    nt--;
                }

                while (nb > 0 && j < limit - 1) {
                    e[j++] = ' ';
                    nb--;
                }
                
                cp += temp;
                state = OUT;

            }

            e[j++] = s[i];
            cp = (s[i] == '\t')? cp + (n - cp%n): cp+1;
        }

        e[j] = '\0';

    }

    return e;
}
