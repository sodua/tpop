#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <ctype.h>

#define MAXOP   100     /* max size of operand or operator */
#define NUMBER  '0'     /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
double ptop(void);
int getch(void);
void ungetch(int);

/* reverse Polish calculator */
int main(void)
{
    int type, dividend, divisor, mod, look;
    int neg = 0;
    double intermediary, op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                if (neg == 0) {
                    op2 = atof(s);
                    break;
                }
                else {
                    printf("%g is thing\n", (atof(s) * -1));
                    pop();
                    op2 = (atof(s) * -1);
                    push(op2);
                    neg = 0;
                    continue;
                }
            case '+':
                push(op2 + pop());
                break;
            case '%':
                divisor = pop();
                if (divisor != 0.0) { 
                    dividend = pop();
                    mod = dividend - (dividend / divisor * divisor);
                    push(mod);
                }
                else
                    printf("error: zero divisor\n");
                break;
            case '*':
                push(pop() * op2);
                break;
            case '-':
                look = getch();
                if (!isdigit(look)) {
                    op2 = pop();
                    push(pop() - op2);
                }
                else {
                    printf("negative number found!\n");
                    neg = 1;
                }
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case 'p':
                printf("%g\n", ptop());
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
        }
    }
    return 0;
}

#define maxval  100     /* maximum depth of val stack */

int sp = 0;             /* next free stack position */
double val[maxval];     /* value stack */

/* push:    push f onto value stack */
void push(double f)
{
    if (sp < maxval)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop:    pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
    }
}

double ptop(void)
{
    if (sp > 0)
        return val[sp] - 1;
    else {
        printf("error: stack empty\n");
    }
}



/* getop:   get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;   /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

char buf[BUFSIZ];   /* buffer for ungetch */
int  bufp = 0;      /* next free position in buf */

int getch(void)     /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZ)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

