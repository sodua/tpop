/* Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the
 * same tab stops as for detab. When either a tab or a single blank would suffice
 * to reach a tab stop, which should be given preference? */

#include <stdio.h>
#define MAXLINE 1000
#define TAB_SIZE 4

int main(void)
{
    int c, i;
    int numspace;       /* consecutive spaces */
    int len;            /* current line length */
    char line[MAXLINE]; /* current input line */
    
    while ((c = getchar()) != EOF) {
        numspace = 0;
        if (c == ' ') {
            ++numspace;
            while ((c = getchar()) == ' ') {
                    ++numspace;
                    }
            while (numspace >= TAB_SIZE) {
                putchar('\t');
                numspace -= 4;
            }
            while (numspace >= 1) {
                putchar(' ');
                --numspace;
            }
        }
        putchar(c);
    }
}
