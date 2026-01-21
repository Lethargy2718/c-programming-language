/*
Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions.
*/

#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main(void)
{

    printf("%u\n", rightrot(4, -2)); // 16
    return 0;
}

unsigned rightrot(unsigned x, int n)
{
    int b = sizeof(x) * 8; // number of bits

    n %= b;

    if (n < 0)
        n += b;

    return (x >> n) | (x << (b - n));
}