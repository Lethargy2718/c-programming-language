/*
Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines.
*/

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length including \0 */

int get_line_trimmed(char s[], int lim);

int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = get_line_trimmed(line, MAXLINE)) >= 0)
    {
        if (len > 0)
            printf("%d: %s", len, line);
    }
    // putchar('\n');
    return 0;
}

/* Read a line into s, return length  */
int get_line_trimmed(char s[], int lim)
{
    int c, i, last_nonblank = -1;

    for (i = 0; (c = getchar()) != EOF && i < lim - 1 && c != '\n'; ++i)
    {
        s[i] = c;

        if (c != ' ' && c != '\t')
        {
            last_nonblank = i;
        }
    }

    // EOF. Check i == 0 in case EOF is reached while reading a line
    if (c == EOF && i == 0)
        return -1;

    // Blank line
    if (last_nonblank < 0)
        return 0;

    i = last_nonblank + 1;

    // Last character was \n
    if (c == '\n')
    {
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}
