#include <stdio.h>
#define MAXLINE 1000

int getline(char [], int);
int remove_trailing_blanks(char [], int);

int main(void) {

    int len, max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0) {
        len = remove_trailing_blanks(line, len);
        if (len > 0)
            printf("%s", line); 
    }

    return 0;
}

int getline(char s[], int lim) {

    int c, i = 0;

    while ((c = getchar()) != EOF && c != '\n' && i < lim-1) {
        s[i++] = c;
    }

    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';

    return i;
}

int remove_trailing_blanks(char s[], int end) {

    end--;

    while (end >= 0 && (s[end] == ' ' || s[end] == '\t')) {
        end--;
    }

    s[end+1] = '\0';
    return end+1;
}