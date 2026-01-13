/*
Exercise 1-8. Write a program to count blanks, tabs, and newlines.
*/

#include <stdio.h>

int main(void)
{
    int b = 0, t = 0, nl = 0, c;

    while ((c = getchar()) != EOF)
    {
        b += (c == ' ');
        t += (c == '\t');
        nl += (c == '\n');
    }

    printf("%d %d %d\n", b, t, nl);
    return 0;
}
