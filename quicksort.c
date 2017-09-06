/* Implementation of a quicksort algorithm from pg. 33
 * of the book The Practice of Programming */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "randnums.h"

#define NELEMS(array) (sizeof(array) / sizeof(array[0]))

int main(int argc, char **argv)
{
    int i;

    quicksort(v, NELEMS(v));
    for (i = 0; i < NELEMS(v); i++)
        printf("%d\n", v[i]);
}

/* quicksort: sort v[0]..v[n-1] into increasing order */
void quicksort(int v[], int n)
{
    int i, last;

    if (n <= 1) /* nothing to do */
        return;
    swap(v, 0, rand() % n); /*  move pivot elem to v[0] */
    last = 0;
    for (i = 1; i < n; i++) /*  partition */
        if (v[i] < v[0])
            swap(v, ++last, i);
    swap(v, 0, last);     /*  restore pivot */
    quicksort(v, last);     /*  recursively sort */
    quicksort(v+last+1, n-last-1);  /* each part */
}

/* swap:    interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
