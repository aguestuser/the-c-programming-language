#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    int i;
    static int c = ' ';

    // resuming at last-stored value of `c`, read until we encounter
    // a non-whitespace char and store it in `c`
    while (c == ' ' || c == '\t')
        c = getchar();
    s[0] = c;
    s[1] = '\0'; // if `c` is non-numeric (:. single-digit) we'll terminate string here;

    // if `c` is non-numeric, we need only consider one character worth of input.
    // we return `c` (thus consuming it from our input stream) and reset the value
    // of `c` to a sentinel whitespace so that the next call to `#getop` will proceed
    // in consuming more chars from the input stream after the check on line 12.
    if (!isdigit(c) && c != '.'){
        int res = c;
        c = ' ';
        return res;
    }

    // read all numeric digits after leading digit of currently considered
    // input into the string, storing the first non-digit we encounter into `c`
    // for use in next call to `#getop` (when we want to resume consuming the input operands
    i = 0;
    if (isdigit(c))  // collect integer part
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') // collect fraction part
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0'; // terminate numerics strings here (since s[1] has been overwritten)

    return NUMBER;
}