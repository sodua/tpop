#include <stdio.h>

void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);

int main(void)
{
    int nums[] = {3, 2, 9, 8, 44, 3, 19, 9, 33, 39, 91, 31, 3, 11, 5};
    int left = 0;
    int right = 14;
    qsort(nums, left, right);
    for (int i = 0; i < 15; i++)
        printf("%d ", nums[i]);
    printf("\n");
}

/* qsort:  sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)      /* do nothing if array contains */
        return;             /* fewer than two elements */
    swap(v, left, (left + right)/2);    /* move partition elem */
    last = left;                        /* to v[0] */
    for (i = left+1; i <= right; i++)   /* partition */
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);        /* restore partition elem */
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap:  interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
