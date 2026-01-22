/*
Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s as a
hexadecimal integer in s.
*/

#include <stdio.h>
#include <limits.h>

#define MAXLINE 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
    int x = 192387;
    char s[MAXLINE + 1];
    itob(x, s, 36);
    printf("%s\n", s);
}

void itob(int n, char s[], int b)
{
    // Invalid base
    if (b < 2 || b > 36)
    {
        s[0] = '\0';
        return;
    }

    int i, sign, digit;
    unsigned num;

    num = (sign = n) < 0 ? -(unsigned)n : (unsigned)n;

    i = 0;
    do
    {
        s[i++] = ((digit = num % b) < 10) ? (digit + '0') : (digit - 10 + 'A');
    } while ((num /= b) > 0);

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