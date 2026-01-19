/*
Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
When either a tab or a single blank would suffice to reach a tab stop, which should be given
preference?
*/

#include <stdio.h>

#define TABSTOPS 4

void entab(int len, int pos, int tabstops);

int main(void)
{
    int c, len = 0, pos = 0;

    while ((c = getchar()) != EOF)
    {
        // Blank
        if (c == ' ')
        {
            len++;
            pos++;
            continue;
        }

        // Not a blank, was reading blanks
        if (len > 0)
        {
            entab(len, pos, TABSTOPS);
            len = 0;
        }

        putchar(c);

        if (c == '\n')
            pos = 0;
        else if (c == '\t')
            pos += TABSTOPS - pos % TABSTOPS;
        else
            pos++;
    }

    if (len > 0)
        entab(len, pos, TABSTOPS);

    return 0;
}

void entab(int len, int pos, int tabstops)
{
    // pos: pos of last blank + 1
    int start_pos = pos - len;                                // first blank
    int blanks_to_next_tab = tabstops - start_pos % tabstops; // blanks to initially place to go to the nearest column

    // No place for even a single tabstop. Just print blanks.
    if (blanks_to_next_tab > len)
    {
        while (len--)
            putchar(' ');
        return;
    }

    // Place a tab to reach the next column
    putchar('\t');
    len -= blanks_to_next_tab;

    // At this point we are exactly at a column. Place as many tabs as possible
    int tabs = len / tabstops;
    for (int i = 0; i < tabs; i++)
        putchar('\t');

    len -= tabs * tabstops;

    // We are also at a column here. So just print any blanks left
    while (len--)
        putchar(' ');
}