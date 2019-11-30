#include <stdio.h>
#include "4-3calc.h"
#define MAXVAL  100     /* maximum depth of val stack */

int sp = 0;             /* next free stack position */

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
