/*
Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.
*/

#include <stdio.h>
#define MAXLINE 100

int get_line(char s[], int lim);

int main(void)
{
    char s[MAXLINE + 1];
    get_line(s, MAXLINE);
    printf("%s", s);
}

int get_line(char s[], int lim)
{
    int i, c = EOF;

    // The loop
    for (i = 0; i < lim - 1; ++i)
    {
        c = getchar();
        if (c == '\n')
            break;
        if (c == EOF)
            break;
        s[i] = c;
    }

    if (c == '\n')
        s[i++] = '\n';

    s[i] = '\0';

    return i;
}