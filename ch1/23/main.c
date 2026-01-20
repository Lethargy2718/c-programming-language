/*
Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest.
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

enum State
{
    DOUBLE,      // Double quotes
    SINGLE,      // Single quotes
    SINGLE_LINE, // Single line comment
    BLOCK,       // Block comment
    OUT          // Default
};

int main(void)
{
    int c;
    int end_asterisk = FALSE, esc = FALSE;
    enum State state = OUT;

    while ((c = getchar()) != EOF)
    {
        if (state == OUT)
        {
            if (c == '/')
            {
                int d = getchar();
                if (d == EOF)
                {
                    putchar(c);
                    break;
                }

                if (d == '/')
                    state = SINGLE_LINE;
                else if (d == '*')
                    state = BLOCK;
                else
                {
                    putchar(c);
                    putchar(d);
                }
            }

            else
            {
                if (c == '"')
                    state = DOUBLE;
                else if (c == '\'')
                    state = SINGLE;
                else
                    putchar(c);
            }
        }

        else if (state == DOUBLE)
        {
            putchar(c);

            if (esc)
                esc = FALSE;
            else
            {
                if (c == '\\')
                    esc = TRUE;
                else if (c == '"')
                    state = OUT;
            }
        }
        else if (state == SINGLE)
        {
            putchar(c);

            if (esc)
                esc = FALSE;
            else
            {
                if (c == '\\')
                    esc = TRUE;
                else if (c == '\'')
                    state = OUT;
            }
        }

        else if (state == SINGLE_LINE)
        {
            if (c == '\n')
            {
                putchar('\n');
                state = OUT;
            }
        }
        else if (state == BLOCK)
        {
            if (c == '*')
                end_asterisk = TRUE;
            else
            {
                if (end_asterisk == TRUE && c == '/')
                    state = OUT;
                end_asterisk = FALSE;
            }
        }
    }

    return 0;
}