#include <stdio.h>

#define OUT 0
#define IN 1
#define STACK_SIZE 1000

/*Exercise 1-24. Write a program to check a C program for rudimentary syntax
errors like unbalanced parentheses, brackets and braces. Don't forget about
quotes, both single and double, escape sequences, and comments. (This program is hard if you do it in full generality.)*/

char get_next_in_char(void);
void push(char *, int *, char);
char pop(char *, int *);
int check(void);

char buffer[STACK_SIZE];
int buffer_tail = 0;
char bracket_stack[STACK_SIZE];
int bracket_tail = 0;

int main(void) {

    if (check()) {
        printf("All good.");
    }else {
        printf("Something is off.");
    }  
    
    return 0;
}

int check(void) {
    
    int c, next_c, state = OUT;

    while ((c = get_next_in_char()) != EOF) {
        if (state == OUT) {
            if (c == '\'') {
                while ((c = get_next_in_char()) != EOF && c != '\'') {;}
            }else if (c == '"') {
                while ((c = get_next_in_char()) != EOF && c != '"') {;}
            }else if (c == '/') {
                next_c = get_next_in_char();
                if (next_c == '/') {
                    while ((c = get_next_in_char()) != EOF && c != '\n') {;}
                } else if (next_c == '*') {
                    state = IN;
                } else {
                    push(buffer, &buffer_tail, next_c);
                }
            }

            if (c == EOF) {
                if (!(bracket_tail))
                    return 1;
                return 0;
            }

            switch (c) {
                case '(':
                    push(bracket_stack, &bracket_tail, '(');
                    break;
                case '[':
                    push(bracket_stack, &bracket_tail, '[');
                    break;
                case '{':
                    push(bracket_stack, &bracket_tail, '{');
                    break;
                case ')':
                    if (pop(bracket_stack, &bracket_tail) != '(')
                        return 0;
                    break;
                case ']': 
                    if (pop(bracket_stack, &bracket_tail) != '[')
                        return 0;
                    break;
                case '}':
                    if (pop(bracket_stack, &bracket_tail) != '{')
                        return 0;
                    break;
                default:
                    break;
            }
        }else {
            if ((c = get_next_in_char()) == '*' && (next_c = get_next_in_char()) == '/') {
                state = OUT;
            }else {
                push(buffer, &buffer_tail, next_c);
            }
        }
    }

    if (!(bracket_tail))
        return 1;
    return 0;
}

char get_next_in_char(void) {
    if (buffer_tail)
        return pop(buffer, &buffer_tail);
    else 
        return getchar();
}

void push(char *stack, int *tail, char c) {
    if (*tail < STACK_SIZE)
        stack[(*tail)++] = c;
    else 
        printf("Stack Overflow!\n");
}

char pop(char *stack, int *tail) {
    if (*tail > 0) 
        return stack[--(*tail)];
    else {
        printf("Nothing to pop here!\n");
        return 'X';
    }
}