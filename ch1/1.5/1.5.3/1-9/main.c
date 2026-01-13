/*
Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank.
*/

#include <stdio.h>

int main(void)
{
    int c;
    int in_blank = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if (!in_blank)
            {
                in_blank = 1;
                putchar(' ');
            }
            continue;
        }
        in_blank = 0;
        putchar(c);
    }

    return 0;
}
