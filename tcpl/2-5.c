/* Write the function any (s1, s2), which returns the first location in the string
 * s1 where any character from the string s2 occurs, or -1 if s1 contains no 
 * characters from s2. (The standard library function strpbrk does the same
 * job but returns a pointer to the location.) */
#include <stdio.h>
int any(char s1[], int c);

int main(void)
{
    char s1[] = "abcdef";
    char s2[] = "jabcdzx";
    int i;

    for (i = 0; s2[i] != '\0'; ++i)
    {
        printf("%d\n", any(s1, s2[i]));
    }
}

int any(char s1[], int c)
{
    int i;
    int found = 0;

    for (i = 0; s1[i] != '\0'; ++i)
    {
        if (s1[i] == c)
        {
            found = 1;
            return i;
        }
    }
    if (!found)
        return -1;
}
