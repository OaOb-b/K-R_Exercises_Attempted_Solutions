#include <stdio.h>
#define MAXLINE 1000
#define ENCOUNTERED 1 
#define NOT_ENCOUNTERED 0

/*Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column. */

int getline(char [], int);
char *fold(char [], char [], int, int);

int main(void) {
    int len;

    char line[MAXLINE];
    char folded[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        printf("%s", fold(line, folded, 8, MAXLINE));
    }

    return 0;
}

int getline(char s[], int limit) {

    int i, c;

    i = 0;
    while ((c = getchar()) != EOF && c != '\n' && i < limit - 1) {
        s[i++] = c;
    }

    if (c == '\n') {
        s[i++] = '\n';
    }

    s[i] = '\0';

    return i;
}

char *fold(char s[], char f[], int n, int limit) {
    int i, j, cp, b, state, br;
    char p, buffer[MAXLINE];

    state = NOT_ENCOUNTERED, b = 0;
    for (i = 0, j = 0, cp = 0, br = 0; s[i] != '\0' && j < limit - 1; i++) {

        // printf("j:%d, br:%d\n", j, br);

        if (cp != 0 && !(cp%n)) {

            buffer[b] = '\0';

            b = 0;
            while (j < br) {
                f[j++] = buffer[b++];
            }
            f[j++] = '\n';

            cp = 0, b++;
            while (buffer[b] != '\0') {
                f[j++] = buffer[b];

                cp = (buffer[b] == '\t')? cp + n - cp%n : cp + 1;
                b++;
            }
            b = 0;
            state = NOT_ENCOUNTERED;
        }

        if (s[i] == ' ') {
            state = ENCOUNTERED;
            br = i;
        }
    
        if (!state) {
            f[j++] = s[i];
            br = j;
        }else {
            buffer[b++] = s[i];
            // printf("hi");
        }

        cp = (s[i] == '\t')? cp + n - cp%n : cp + 1;
    }

    f[j] = '\0';

    return f;

}