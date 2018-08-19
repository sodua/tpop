/* Write an alternate version of squeeze(s1, s2) that deletes each character in s1
 * that matches any character in the string s2. */
#include <stdio.h>
void squeeze(char s1[], int c);

int main(void)
{
    char s1[] = "abc";
    char s2[] = "abxyz";
    int i;

    for (i = 0; s2[i] != '\0'; ++i)
    {
        printf("calling squeeze with s1 and s2[%d] (%c)\n\n", i, s2[i]);
        squeeze(s1, s2[i]);
    }
    
    printf("\ncharacters unique to s1: ");
    for (i = 0; s1[i] != '\0'; ++i)
        printf("%c", s1[i]);
    printf("\n");
}

void squeeze(char s1[], int c)
{
    int i, j;

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] != c)
        {
            printf("s1[%d] != %c (because it is %c)\n", i, c, s1[i]);
            s1[j++] = s1[i];
        }
        else
            printf("match found! deleting: %c from: s1[%d]\n", s1[i], i);
    }
    s1[j] = '\0';
    printf("\n");
}
