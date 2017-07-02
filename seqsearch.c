#include <stdio.h>

int main(int argc, char **argv)
{
    char *flab[] = {
        "actually",
        "just",
        "quite",
        "really",
        NULL
    };
    
    int result = lookup(argv[1], flab);
    printf(flab[result]);
    printf("\n");
}
/* lookup: sequential search for word in array */
int lookup(char *word, char *array[])
{
    int i;
    for (i = 0; array[i] != NULL; i++)
        if (strcmp(word, array[i]) == 0)
            return i;
    return -1;
}
