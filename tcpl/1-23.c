/*
 * Write a program to remove all comments from a C program. Don't forget to handle
 * quoted strings and character constants properly. C comments do not nest.
 */
#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */
#define WRAPCOL 60

int mygetline(char s[], int lim);

int main(void)
{
    char line[MAXLINE];         /* current line */
    int inside = 0;
    int c, len, i;
    
    while ((len = mygetline(line, MAXLINE)) > 0) {
		for (i = 0; i < len; ++i) {
            if (line[i] == '/' && line[i+1] == '*') {
                inside = 1;
            }
            if (!inside) {
                printf("%c", line[i]);
            }
            if ((inside) && line[i] == '*' && line[i+1] == '/') {
                if (line[i+2] == '\n') {
                    ++i;
                }
                inside = 0;
                ++i;
            }
        } 
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
        i++;
    }
    s[i] = '\0';
    return i;
}
