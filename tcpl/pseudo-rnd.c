#include <stdio.h>

int rand(void);
void srand(unsigned int seed);

unsigned long int next = 1;

int main(void)
{
    for (int i = 0; i < 10; ++i)
    {
        srand(next);   
        printf("%d\n", rand()); 
    }
}

/* rand:    return pseudo-random integer on 0..32767 */
int rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next/65536) % 32768;
}

/* srand: set seed for rand() */
void srand(unsigned int seed)
{
    next = seed;
}
