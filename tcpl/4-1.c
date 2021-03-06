/* 
 * Write the function strrindex(s,t) which returns the position of the rightmost
 * occurence of t in s, or -1 if there is none.
 */
#include <stdio.h>

int mygetline(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";    /* pattern to search for */

/* find all lines matching pattern */
int main(void)
{
    char line[BUFSIZ];
    int found = 0;

    while (mygetline(line, BUFSIZ) > 0)
        if (strrindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    return found;
}

/* mygetline: get line into s, return length */
int mygetline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strrindex: return index of rightmost occurence of t in s, -1 if none */
int strrindex(char s[], char t[])
{
    int i, j, k;
    int found = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0') {
            found = i;
        }
    }
    printf("%d\n", found);
    return found;
}
