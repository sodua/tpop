/* Write an alternate version of squeeze(s1, s2) that deletes each character in s1
 * that matches any character in the string s2. */
#include <stdio.h>
void squeeze(char s1[], char s2[]);

int main(void)
{
    squeeze("abc", "adef");
}

void squeeze(char s1[], char s2[])
{
    int i, j;

    for (i = j = 0; s2[i] != '\0'; i++)
        while (s1[j] != s2[i])
            s1[j++] = s1[j];
    s[j] = '\0';
}
