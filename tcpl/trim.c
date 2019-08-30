#include <stdio.h>
#include <string.h>
int trim(char s[]);

int main(void)
{
    char s[] = "test\t";
    trim(s);
    for (int i = 0; i < strlen(s); i++)
        printf("%c", s[i]);
}

int trim(char s[])
{
    int n;

    for (n = strlen(s)-1; n >= 0; n--)
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    s[n+1] = '\0';
    return n;
}
