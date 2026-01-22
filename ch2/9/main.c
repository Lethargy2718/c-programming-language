/*
Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x. Explain why. Use this observation to write a faster version of bitcount.
*/

#include <stdio.h>

unsigned bitcount(unsigned x);

int main(void)
{

    printf("%u\n", bitcount(7)); // 111 => three 1's
    return 0;
}

unsigned bitcount(unsigned x)
{
    /*
        1001 - 1 = 1000, 1001 & 1000 = 1000
        1010 - 1 = 1001, 1010 & 1001 = 1000

        The rightmost 1 is always deleted because subtracting borrows from the rightmost 1.
        Whatever comes afterwards becomes 0.

        So when you &, everything starting from that 1 you borrowed from until the end becomes 0.

        It's fine for the bits that come after to be zero because they were 0 anyways since we
        picked the rightmost 1.

        So to count 1's, we keep deleting 1's until x = 0 while incrementing a counter.
    */

    int i;
    for (i = 0; x != 0; x &= (x - 1), i++)
        ;

    return i;
}