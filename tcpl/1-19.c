#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

void reverse(char to[], char from[], int lim);
int mygetline(char s[], int lim);

int main(void)
{
    char forward[MAXLINE];
    char backward[MAXLINE];
    int c, len, i;
    
    while ((len = mygetline(forward, MAXLINE)) > 0) {
        reverse(backward, forward, len);
        for (i = 0; i < len; i++)
            printf("%c", backward[i]);
    }
    printf("\n");

    return 0;
}

void reverse(char to[], char from[], int lim)
{
    int i, j;

    i = 0;
    j = lim - 1;
    while((to[j] = from[i]) != '\0') {
        ++i;
        --j;
    }
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
