/*
Exercise 3-4. In a two's complement number representation, our version of itoa does not
handle the largest negative number, that is, the value of n equal to -2^(wordsize-1). Explain why
not. Modify it to print that value correctly, regardless of the machine on which it runs.
*/

#include <stdio.h>
#include <limits.h>

#define MAXLINE 1000

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void)
{
    int x = INT_MIN;
    char s[MAXLINE + 1];
    itoa(x, s);
    printf("%s\n", s);
}

void itoa(int n, char s[])
{
    /*
        if ((sign = n) < 0)
            n = -n; // this line was the problem

        If it's the minimum integer, it can't be represented as a positive signed integer.

        Min = -2^(n-1)
        Max = 2^(n-1) - 1

        It would overflow by 1.
        Ex: 10000000 becomes 01111111 + 1 = 10000000
        So negating it just forms the same number.


        To solve this, store the magnitude as an unsigned value instead.
        They can house all numbers between 0 and 2^n - 1 (255 for 8 bits),
        so 10000000 would be viewed as 128 as expected.

        For numbers other than INT_MIN, it would still work since negating
        a number removes the sign bit anyways which is the only differentiator
        between signed and unsigned values. So signed = unsigned for numbers
        other than INT_MIN as well.
    */

    int i, sign;
    unsigned num;

    num = (sign = n) < 0 ? -(unsigned)n : (unsigned)n;

    i = 0;
    do
    {
        s[i++] = num % 10 + '0';
    } while ((num /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int len = 0;
    while (s[len] != '\0')
        len++;

    for (int i = 0; i < len / 2; i++)
    {
        char tmp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = tmp;
    }
}