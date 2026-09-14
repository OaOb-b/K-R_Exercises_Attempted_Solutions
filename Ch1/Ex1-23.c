#include <stdio.h>
#define IN_COMMENT 1
#define OUT_COMMENT 0
#define IN_STRING 3
#define OUT_STRING 4

#define MAXLENGTH 1000

/*Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest. */

// It can be double slash
/* or it can be asterisk slash*/

// when we are in a comment, we don't care what's inside
// likewise when we are in a string literal we don't care what's inside
  
char *remove_comment(char [], char []);

int main(void) {
    int c, i;
    char program_w_comment[MAXLENGTH];
    char program[MAXLENGTH];

    i = 0;
    while ((c = getchar()) != EOF && i < MAXLENGTH - 1) {
            program_w_comment[i++] = c;
        }
    program_w_comment[i] = '\0';
    
    remove_comment(program_w_comment, program);
    printf("%s", program);

    return 0;
}

char *remove_comment(char sc[], char dest[]) {
    int i, j, state;

    i = 0, j = 0, state = 0;
    while (i < MAXLENGTH && sc[i] != '\0') {
       
        if (i < MAXLENGTH - 1 && sc[i] == '\'') {
            dest[j++] = sc[i++];
            while (i < MAXLENGTH - 1 && sc[i] != '\'') {dest[j++] = sc[i++];}
        }else if (i < MAXLENGTH - 1 && sc[i] == '"') {
            dest[j++] = sc[i++];
            while (i < MAXLENGTH - 1 && sc[i] != '"') {dest[j++] = sc[i++];}
        }else if (i < MAXLENGTH - 2 && sc[i] == '/' && sc[i+1] == '/') {
            i = i + 2;
            while (i < MAXLENGTH - 1 && sc[i] != '\n') {i++;}
        }else if (i < MAXLENGTH - 2 && sc[i] == '/' && sc[i+1] == '*') {
            i = i + 2;
            while (i < MAXLENGTH - 2 && !(sc[i] == '*' && sc[i+1] == '/')) {i++;}
            i = i + 2;
        }

        if (!(i < MAXLENGTH)) {
            break;
        }

        dest[j++] = sc[i++];
    } 
    dest[j] = '\0';
    return dest;
}