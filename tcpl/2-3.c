/* Write the function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value.
 * The allowable digits are 0 through 9, a through f, and A through F. */

#include <stdio.h>
#define MAXLINE 1000

int htoi(char s);
int mygetline(char line[], int maxline);
int power(int base, unsigned int exp);
int main(void)
{
    int len, mult;
    int j = 0;
    int tally = 0;
    char line[MAXLINE];
    len = mygetline(line, MAXLINE);
    for (int i = len - 1; i >= 0; --i)
    {
        mult = power(16, i);
        tally += htoi(line[j]) * mult;
        ++j;
    }
    printf("%d\n", tally);

}

int power(int base, unsigned int exp)
{
    int i, result = 1;
    for (i = 0; i < exp; ++i)
        result *= base;
    return result;
}
int htoi(char s)
{
    if (s == '0' || s == 'x' || s == 'X')
        return 0;
    if (s == '1')
        return 1;
    if (s == '2')
        return 2;
    if (s == '3')
        return 3;
    if (s == '4')
        return 4;
    if (s == '5')
        return 5;
    if (s == '6')
        return 6;
    if (s == '7')
        return 7;
    if (s == '8')
        return 8;
    if (s == '9')
        return 9;
    if (s == 'a' || s == 'A')
        return 10;
    if (s == 'b' || s == 'B')
        return 11;
    if (s == 'c' || s == 'C')
        return 12;
    if (s == 'd' || s == 'D')
        return 13;
    if (s == 'e' || s == 'E')
        return 14;
    if (s == 'f' || s == 'F')
        return 15;
    else
        return 0;
}


/* getline: specialized version */
int mygetline(char s[], int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    return i;
}
