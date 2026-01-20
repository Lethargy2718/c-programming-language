/*
Exercise 1-22. Write a program to "fold" long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.
*/

#include <stdio.h>

#define TABSTOP 4
#define MAXCOLS 5
#define UNDEFINED -1

void partial_print(int pos);
int fold_line(int pos, int line_size, int *lbc);

char line[MAXCOLS];

int main(void)
{
    int c, pos, lbc;
    pos = 0;
    lbc = UNDEFINED;

    while ((c = getchar()) != EOF)
    {
        // Fold: print until last blank, fold the end of the array to the beginning
        if (c == '\n')
        {
            partial_print(pos - 1);
            pos = 0;
            continue;
        }

        if (c == '\t')
        {
            int spaces = TABSTOP - pos % TABSTOP;
            int spaces_left = MAXCOLS - pos;
            int final_spaces = spaces_left < spaces ? spaces_left : spaces;

            while (final_spaces--)
            {
                line[pos++] = ' ';
            }
            continue;
        }

        if (pos >= MAXCOLS)
        {
            if (lbc == UNDEFINED)
            {
                // No blanks found, print the whole line which is full
                partial_print(MAXCOLS - 1);
                pos = 0;
            }
            else
            {
                // Print until the last blank
                partial_print(lbc);
                pos = fold_line(lbc + 1, MAXCOLS, &lbc);
            }
        }

        line[pos] = c;

        if (c == ' ')
            lbc = pos;

        pos++;
    }

    if (pos > 0)
        partial_print(pos - 1);
}

// print until position `pos` inclusive
void partial_print(int pos)
{
    for (int i = 0; i <= pos; i++)
    {
        putchar(line[i]);
    }
    putchar('\n');
    return;
}

// fold from position `pos` until the end and return the length of the new line
int fold_line(int pos, int line_size, int *lbc)
{
    int i = 0;
    *lbc = UNDEFINED;
    while (pos < line_size)
    {
        line[i] = line[pos++];
        if (line[i] == ' ')
        {
            *lbc = i;
        }
        i++;
    }

    return i;
}