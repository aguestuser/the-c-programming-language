#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include "calc.h"

/**
 * Exercise 5-1.
 * As written, getint treats a + or - not followed by a digit as a valid representation of zero.
 * Fix it to push such a character back on the input.
 **/

#define LIMIT 1000
#define NON_INTEGER 0

int getint(int *);

int main(){
    int i=0, ns[LIMIT], r;
    printf("Input an int...\n");
    while((r = getint(&ns[i++])) != EOF){
        switch(r){
            case EOF:
                printf("...found: EOF\n");
                break;
            case NON_INTEGER:
                printf("...found: NON_INTEGER\n");
                break;
            default:
                printf("...found: INTEGER\n");
                printf("   value: %d\n", ns[i-1]);
                break;
        }
    }
}

/* getint: get next integer from input into *pn */
int getint(int *pn) {
    // TODO: fix so ungetch calls don't cause infinite loop for non-integers
    int c, sign;
    bool is_zero;
    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        // ungetch(c); /*it's not a number*/
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-' )
        c = getch();
    for (*pn = 0; isdigit(c); c = getch()){
        *pn = 10 * *pn + (c - '0');
        is_zero = c == '0';
    }
    //if +/- is followed by NaN, pn will stay at 0
    if (*pn == 0 && !is_zero)	{
        // ungetch(sign == 1 ? '+' : '-');
        return 0;
    }
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
