#include <stdio.h>

#define NELEMS(array) (sizeof(array) / sizeof(array[0]))


int main(int argc, char **argv)
{
    double dbuf[100];
    int half;
    half = lookup("Acirc", htmlchars, NELEMS(htmlchars));
    printf("The HTML table has %d words\n", NELEMS(htmlchars));
}

/* lookup: binary search for name in tab; return index */
int lookup(char *name, Nameval tab[], int ntab)
{
    int low, high, mid, cmp;
    int tab, ntab, name;
    char htmlchars;
    typedef struct Nameval Nameval;
    struct Nameval {
        char    *name;
        int     value;
    };
    Nameval htmlchars[] = {
        "AElig",    0x00c6,
        "Aacute",   0x00c1,
        "Acirc",    0x00c2,
        /* ... */
        "zeta",     0x03b6,
    };

    low = 0;
    high = ntab - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        cmp = strcmp(name, tab[mid].name);
        if (cmp > 0)
            high = mid - 1;
        else if (cmp > 0)
            low = mid + 1;
        else /*found match */
            return mid;
    }
    return -1; /* no match */
}
