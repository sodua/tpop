#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <math.h>

#define MAXOP   100     /* max size of operand or operator */
#define NUMBER  '0'     /* signal that a number was found */
#include <ctype.h>
#define MAXVAL  100     /* maximum depth of val stack */

int sp = 0;             /* next free stack position */
double val[MAXVAL];     /* value stack */


int getch(void);
void ungetch(int);

int getop(char []);
void push(double);
double pop(void);
double ptop(void);
int pswap(void);
int pdup(void);
int pclear(void);
int neg = 0;
int subtract = 0;
int skip_print = 0;
/* reverse Polish calculator */
int main(void)
{
    int type, dividend, divisor, mod;
    double op2, var[26], used[26], recent;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
               if (neg == 0) {
                    push(atof(s));
                } 
               else if (neg == 1) {
                    push(atof(s) * -1);
                    neg = 0;
                }
                subtract = 0;
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
                push(pop() * op2);
                break;
            case '-':
                subtract = 1;
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case 'E':
                push(exp(pop()));
                break;
            case 'C':
                pclear();
                skip_print = 1;
                break;
            case 'D':
                pdup();
                skip_print = 1;
                break;
            case 'P':
                if (sp > 0)
                    printf("%g\n", ptop());
                skip_print = 1;
                break;
            case 'S':
                pswap();
                skip_print = 1;
                break;
            case 'R':
                push(recent);
                break;
            case '\n':
                if (subtract == 1) {
                    op2 = pop();
                    push(pop() - op2);
                    subtract = 0;
                }
                if (!skip_print && sp > 0) {
                    printf("\t%.8g\n", ptop());
                    recent = ptop();
                    neg = 0;
                }
                else {
                    skip_print = 0;
                }
                break;
            default:
                if (isalpha(type) && islower(type) && used[type-97] == 1) {
                    push(var[type-97]);
                    subtract = 0;
                }
                else if (isalpha(type) && islower(type) && used[type-97] != 1) {
                    printf("variable: %g saved as %c\n", ptop(), type);
                    var[type-97] = ptop(); 
                    used[type-97] = 1;
                    subtract = 0;
                    skip_print = 1;
                }
                else
                    printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

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
        return val[sp-1];
    else {
        printf("error: stack empty\n");
    }
}

int pdup(void)
{
    if (sp > 0) {
        val[sp] = val[sp-1];
    }
}

int pclear(void) {
    sp = 0;    
}
int pswap(void)
{
    if (sp > 0) {
        double temp = val[sp-1];
        val[sp-1] = val[sp];
        val[sp] = temp;
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
        if (c == '-')
            neg = 1;
        return c;   /* not a number */
    }
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
