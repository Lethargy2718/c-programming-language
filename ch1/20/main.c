/*
Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter?
*/

#include <stdio.h>

#define TABSTOPS 4

int main(void)
{
    int c, pos = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            int spaces = TABSTOPS - pos % TABSTOPS;
            pos += spaces;
            while (spaces--)
            {
                putchar(' ');
            }
            continue;
        }

        putchar(c);

        if (c == '\n')
            pos = 0;
        else
            pos++;
    }
    return 0;
}