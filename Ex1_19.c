#include <stdio.h>
#define MAXLINE 1000

int getline(char [], int);
void reverse(char []);

int main(void) {
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s", line);
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

void reverse(char s[]) {
    char temp;
    int n, i;

    n = 0;
    while (s[n] != '\n') {
        n++;
    }

    for (i = 0; i < n/2; i++) {
        temp = s[i];
        s[i] = s[n-1-i];
        s[n-1-i] = temp; 
    }
}