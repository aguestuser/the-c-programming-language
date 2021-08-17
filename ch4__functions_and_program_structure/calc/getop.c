#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    int i, c;
    // discard whitespace
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    // return if not a number
    if (!isdigit(c) && c != '.')
        return c;
    // collect a number
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ; // collect integer part
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ; // collect fraction part
    s[i] = '\0';
    // backtrack if needed
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}