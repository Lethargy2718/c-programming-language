/*
Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time.
*/

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int get_line_trimmed(char line[], int maxline);
void reverse_string(char s[], int len);

int main(void)
{
    int len;            /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = get_line_trimmed(line, MAXLINE)) >= 0)
    {
        if (len == 0)
            continue;

        reverse_string(line, len);
        printf("%s", line);
    }
    return 0;
}

/* read a line into s, return length */
int get_line_trimmed(char s[], int lim)
{
    int c = EOF, i, last_nonblank = -1;

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

void reverse_string(char s[], int len)
{
    if (s[len - 1] == '\n')
        len--;

    for (int i = 0; i < len / 2; i++)
    {
        int tmp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = tmp;
    }
}