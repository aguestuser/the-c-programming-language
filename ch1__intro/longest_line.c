#include <stdio.h>
#define MAXLINE 1000 /* max input line size */

int get_line(char s[], int lim);
void copy(char from[], char to[]);

/* print longest input line */
int main()
{
    int len;                    /* current line length */
    int max;                    /* maximum lenght seen so far */
    char line[MAXLINE];         /* current input line */
    char longest[MAXLINE];      /* longest line saved here */

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max){
            max = len;
            copy(line, longest);
        }
    if (max > 0)                /* there was a line */
        printf("%s", longest);

    return 0;
}

/* get_line: read a line into s, return lenght */
int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy `from` into `to`; assume it's big enough */
void copy(char from[], char to[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
    
