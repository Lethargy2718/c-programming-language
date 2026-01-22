/*
Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with blanks on the
left if necessary to make it wide enough.
*/

#include <stdio.h>
#include <limits.h>

#define MAXLINE 1000

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main(void)
{
    int x = 111;
    char s[MAXLINE + 1];
    itoa(x, s, 6);
    printf("%s\n", s);
}

void itoa(int n, char s[], int w)
{
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

    while (i < w)
        s[i++] = ' ';

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