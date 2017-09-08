#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "words.h"

#define NELEMS(array) (sizeof(array) / sizeof(array[0]))

int lookup(char *name, Nameval tab[], int ntab);

int main(int argc, char **argv)
{
    int half;
    half = lookup(argv[1], dictwords, NELEMS(dictwords));
    printf("%d\n", half);
//    printf("The HTML table has %d words\n", NELEMS(dictwords));
}

/* lookup: binary search for name in tab; return index */
int lookup(char *name, Nameval tab[], int ntab)
{
    int low, high, mid, cmp;

    low = 0;
    high = ntab - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        printf("mid now %d\n", mid);
        cmp = strcmp(name, tab[mid].name);
        printf("comparison value: %d\n", cmp);
        if (cmp < 0) {
            high = mid - 1;
            printf("searching down, high=%d", high);
            printf("\n");
        }
        else if (cmp > 0) {
            low = mid + 1;
            printf("searching up, low=%d", low);
            printf("\n");
        }
        else /*found match */ {
            printf("found! index=%d", mid);
            printf("\n");
            return mid;
        }
    }
    return -1; /* no match */
}
