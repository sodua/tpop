#include <stdio.h>
#define MAXLINE 1000    #define WRAPCOL 60

int mygetline(char s[], int lim);

int main(void)
{
    char line[MAXLINE];             int lastspace;                  int c, len, i;
    int still = 0;
    
    while ((len = mygetline(line, MAXLINE)) > 0) {
        if (len < WRAPCOL) {
            for (i = 0; i < len; ++i) {
                if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n') {
                    lastspace = i;
                }
            }
            for (i = 0; i < lastspace + 1; ++i)
                printf("%c", line[i]);
            printf("\n");
        }
        if (len > WRAPCOL) {
            while (len > 0) {
                for (i = 0; i < WRAPCOL; ++i) {
                    if (line[i] != ' ' && line[i] !='\t' && line[i] != '\n') {
                        lastspace = i;
                    }
                }
                for (i = 0; i < lastspace; ++i) {
                    if (line[still] != '\n') {
                        printf("%c", line[still]);
                        ++still;
                    }
                }
                printf("\nlen = %d, i = %d, still = %d\n", len, i, still);
                len -= still;
                printf("\n");
            }
        }
    }

    return 0;
}


int mygetline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}
