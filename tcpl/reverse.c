#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main(void)
{
    char reversethis[5] = "zzzaa";
    reverse(reversethis);
    for (int i = 0; i < 5; i++)
        printf("%c", reversethis[i]);
    printf("\n");
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
