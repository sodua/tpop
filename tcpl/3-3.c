/* Write a function expand(s1,s2) that expands shorthand notations like a-z
 * in the string s1 into the equivalent complete list abc...xyz in s2. Allow
 * for letters of either case and digits, and be prepared to handle cases
 * like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is
 * taken literally.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
void expand(char s1[], char s2[]);
    
int main(void)
{
    int i;
    char s1[4] = "b-x";
    char s2[37];
    for (i = 0; i < 36; i++)
        s2[i] = '\0';
    expand(s1, s2);
    for (i = 0; i < 36; i++)
        printf("%c", s2[i]);
    printf("\n");
}

void expand(char s1[], char s2[])
{
    int i, j, ifrom, ito;
    char lower[27] = "abcdefghijklmnopqrstuvwxyz";
    char upper[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[11] = "0123456789";
    char from = '\0';
    char to = '\0';

    for (i = 0; i < strlen(s1); i++) {
        if (s1[i] == '-' && !(from))
            printf("%c", s1[i]);
        if (isalnum(s1[i])) {
            from = s1[i];
            printf("from: %c\n", from);
            i++;
        }
        if (s1[i] == '-' && (from))
            i++;
        if (isalnum(s1[i]) && isalpha(from)) {
            to = s1[i]; 
            printf("to: %c\n", to);
        }
        for (i = 0; i < strlen(lower); i++)
            if (from == lower[i]) {
                ifrom = i;
                printf("ifrom: %d\n", ifrom);
            }
        for (i = 0; i < strlen(lower); i++)
            if (to == lower[i]) {
                ito = i;
                printf("ito: %d\n", ito);
                printf("strlen(lower): %d\n", strlen(lower));
            }

    }
    for (j = 0, i = ifrom; i <= ito; i++, j++)
        s2[j] = lower[i];
}
