#include <stdio.h>
#define MAXLINE 1000

int getline(char [], int);
char *detab(char [], char [], int, int);

int main(void) {
    int len;
    char line[MAXLINE];
    char detabbed[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        printf("%s", detab(line, detabbed, 8, MAXLINE));
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

char *detab(char s[], char d[], int n, int limit) {
    int i, j, nb;

    for (i = 0, j = 0; s[i] != '\0' && j < limit-1; i++) {
        if (s[i] == '\t') {
            nb = n - j%n;
            while (nb-- > 0) {
                d[j++] = ' ';
            }
        }else {
            d[j++] = s[i];
        }
    }

    d[j] = '\0';

    return d;
}