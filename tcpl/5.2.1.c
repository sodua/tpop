#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);
int getint(int *pn);

char buf[BUFSIZ];
int bufp = 0;

int main(void)
{
    int c;
    while ((getint(&c)) != EOF) {
        printf("%d is c\n", c);
    }
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))    /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);     /* it's not a number */
        printf("NAN\n");
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZ)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
