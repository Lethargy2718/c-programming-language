/*
Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print
the length of arbitrary long input lines, and as much as possible of the text.
*/

#include <stdio.h>
#define MAXLINE 5 /* maximum input line length including \0 */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
void update_data(int read_len, int len, int *max, char longest[], char line[]);

int main(void)
{
    char line[MAXLINE];
    char longest[MAXLINE];
    int max = 0, len = 0, read_len = 0, actual_max;
    int c;

    while ((c = getchar()) != EOF)
    {
        // new line
        if (c == '\n')
        {
            update_data(read_len, len, &max, longest, line);

            len = 0;
            read_len = 0;
        }
        // still in the same line
        else
        {
            if (read_len < MAXLINE - 1)
            {
                line[read_len++] = c;
            }

            len++;
        }
    }

    // final update in case the final character wasn't a newline
    update_data(read_len, len, &max, longest, line);

    max = len > max ? len : max;
    actual_max = max < MAXLINE - 1 ? max : MAXLINE - 1;
    longest[actual_max] = '\0';

    printf("Longest read line: %s\n", longest);
    printf("Its length: %d\n", actual_max);
    printf("Actual longest found length: %d\n", max);

    return 0;
}

/* copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

/* update data on moving to a new line */
void update_data(int read_len, int len, int *max, char longest[], char line[])
{
    if (len > *max)
    {
        *max = len;
        copy(longest, line);
    }
}
