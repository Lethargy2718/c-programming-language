/*
Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged.
*/

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{

    printf("%u\n", setbits(0630, 5, 3, 0223));
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned mask = ((1 << n) - 1) << (p - n + 1);
    return (x & ~mask) | (y << (p - n + 1) & mask);
}