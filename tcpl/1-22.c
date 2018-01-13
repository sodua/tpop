/* Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before the specified column.
 */
#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */
#define WRAPCOL 60

int mygetline(char s[], int lim);

int main(void)
{
    char line[MAXLINE];         /* current line */
    int lastspace;              /* column location of last space in line */
    int c, len, i;
    int still = 0;
    
    while ((len = mygetline(line, MAXLINE)) > 0) {
        if (len < WRAPCOL) {
            for (i = 0; i < len; ++i)
                printf("%c", line[i]);
        }
        if (len > WRAPCOL) {
            while (len > 0) {
                for (i = 0; i < WRAPCOL; ++i) {
                    if (line[i] != ' ' || line[i] !='\t')
                        lastspace = i;
                }
                for (i = 0; i < lastspace; ++i) {
                    if (line[still] != '\n') {
                        printf("%c", line[still]);
                        ++still;
                    }
                }
                len -= still;
                printf("\n");
            }
        }
       still = 0;
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
