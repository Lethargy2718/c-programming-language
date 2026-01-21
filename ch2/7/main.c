/*
Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void)
{

    printf("%u\n", invert(0630, 5, 3));
    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned mask = ((1 << n) - 1) << (p - n + 1);
    return x ^ mask; // (x & ~mask) | (~x & mask) = x ^ mask
}