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
    int max;        /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */
    int i;

    max = 0;
    while ((len = mygetline(line, MAXLINE)) > 0) {
        i = 2; 
        if (len > 1)
            copy(longest, line);
        while (longest[len - i] == '\t' || longest[len - i] == ' ') {
            longest[len - i] = '\0';
            ++i;
        }
        printf("%s\n", longest);
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
        s[i] = c;
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
