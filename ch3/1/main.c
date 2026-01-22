/*
Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case,
with a conditional expression instead of if-else.
*/

#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(void)
{
    int arr[] = {2, 4, 6, 8, 10};
    printf("%d\n", binsearch(4, arr, 5));
    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while (low < high && v[mid] != x)
    {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }

    return v[mid] == x ? mid : -1;
}
