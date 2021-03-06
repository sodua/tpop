/* this version does not exit gracefully
 * if match is not found */

#include <stdio.h>
#include "words.h"
#define NELEMS(array) (sizeof(array) / sizeof(array[0]))

int lookup(char *name, Nameval tab[], int ntab);

int main(int argc, char **argv)
{
    int result = lookup(argv[1], dictwords, NELEMS(dictwords));
    printf("%d", result);
    printf("\n");
}
/* lookup: sequential search for word in array */
int lookup(char *name, Nameval tab[], int ntab)
{
    int i;
    for (i = 0; tab[i].name != NULL; i++)
        if (strcmp(name, tab[i].name) == 0)
            return i;
    return -1;
}
