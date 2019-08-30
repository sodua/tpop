#include <stdio.h>
void shellsort(int v[], int n);

int main(void)
{
    int sortthis[5] = {9,0,2,55,1};
    shellsort(sortthis, 5);
    for (int i = 0; i < 5; i++)
        printf("%d ", sortthis[i]);
    printf("\n");
}

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}
