#include <stdio.h>

int main(void) {

    int c;
    int n_blank = 0, n_tab = 0, n_newline = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') n_blank++;
        else if (c == '\t') n_tab++;
        else if (c == '\n') n_newline++;
    }
    printf("no. of blanks= %d\nno. of tabs= %d\nno. of newlines= %d\n", n_blank, n_tab, n_newline);
    
    return 0;
}