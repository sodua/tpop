#include <stdio.h>
#include <stdlib.h>     /* for atof() */

#define MAXOP   100     /* max size of operand or operator */
#define NUMBER  '0'     /* signal that a number was found */
#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char []);
void push(double);
double pop(void);
double ptop(void);
int neg = 0;
int opcount = 0;
/* reverse Polish calculator */
int main(void)
{
    int type, dividend, divisor, mod, look;
    double op1, op2, result, negval, posval;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
               if (neg == 0) {
                    posval = atof(s);
                    printf("posval being pushed onto stack: %g\n", posval);
                    push(posval);
                    opcount++;
                    printf("opcount is: %d\n", opcount);
                } 
               else if (neg == 1) {
                    negval = atof(s);
                    negval *= -1;
                    printf("negval being pushed onto stack: %g\n", negval);
                    push(negval);
                    opcount++;
                    neg = 0;
                }
                break;
            case '+':
                push(pop() + pop());
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
                op2 = pop();
                op1 = pop();
                printf("%g is op2!!!\n", op2);
                printf("%g is op1!!!\n", op1);
                result = op1 * op2;
                push(result);
                break;
            case '-':
                if (opcount == 2) {
                    op2 = pop();
                    printf("JUST POPPED FROM SUBTRACT!\n");
                    push(pop() - op2);
                }
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case 'P':
                printf("%g\n", ptop());
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                neg = 0;
                opcount = 0;
                break;
        }
    }
    return 0;
}

#define MAXVAL  100     /* maximum depth of val stack */

int sp = 0;             /* next free stack position */
double val[MAXVAL];     /* value stack */

/* push:    push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
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
        printf("error: stack empty from pop\n");
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
    if (!isdigit(c) && c != '.') {
        if (c == '-' && opcount < 2) {
            neg = 1;
            printf("NEGATIVE BIT SET!\n");
        }
        printf("not a digit or dot: %d\n", c);
        return c;   /* not a number */
    }
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    for (int j = 0; j < i; j++)
        printf("VALUE: %c is s[j]\n", s[j]);
    if (c != EOF) {
        printf("character that is not EOF: %d\n", c);
        ungetch(c);
    }

    return NUMBER;
}

char buf[BUFSIZ];   /* buffer for ungetch */
int  bufp = 0;      /* next free position in buf */

int getch(void)     /* get a (possibly pushed back) character */
{
    printf("current bufp value: %d\n", bufp);
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZ)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

