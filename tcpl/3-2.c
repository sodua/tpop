/* Write a function escape(s, t) that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copies the string t to s.
 * Use a switch. Write a function for the other direction as well, converting
 * escape sequences into the real characters.
 */
#include <stdio.h>
int escape(char s[], char t[]);
int main(void)  /* count digits, white space, others */
{
    int i = 0;
    int c, len;
    char s[BUFSIZ], t[BUFSIZ];
    while ((c = getchar()) != EOF) {
        t[i] = c;
        i++;
    }
    for (i = 0; i < BUFSIZ; i++)
        escape(s, t);
    for (i = 0; i < BUFSIZ; i++)
        putchar(s[i]);
    return 0;
}

int escape(char s[], char t[])
{
    int i, j = 0;

    for (i = 0; i < BUFSIZ; j++) {
        switch(t[j]) {
            case '\t':
               s[++i] = '\\';
               s[++i] = 't';
               break;
            case '\n':
               s[++i] = '\\';
               s[++i] = 'n';
               break;
            default:
               s[++i] = t[j];
               break;
        }
    }
}
