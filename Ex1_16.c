#include <stdio.h>
#define MAXLINE 1000

int getline(char [], int);
void copy(char [], char []);

int main(void) {

    int len, max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {
        printf("%s", longest);
    }

    return 0;
}

int getline(char s[], int lim) {

    int c, i = 0;

    while ((c = getchar()) != EOF && c != '\n') {
        if (i < lim-1) 
            s[i] = c;
        i++;
    }
    if (i < lim-1) {
        if (c == '\n') {
            s[i++] = c;
        }
        s[i] = '\0';
    }else {
        s[lim-1] = '\0';
    }
    return i;
}

void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}
