/* Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines */
#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main(void)
{
    int len;        /* current line length */
    char line[MAXLINE];     /* current input line */
    int i;

    while (len = mygetline(line, MAXLINE)) {
        i = 2; 
        while (line[len - i] == '\t' || line[len - i] == ' ') {
            line[len - i] = '\0';
            ++i;
        }
        if (len > 1)
            printf("%s\n", line);
    }
    return 0;
}

/* mygetline: read a line into s, return length */
int mygetline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = '\0';
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
