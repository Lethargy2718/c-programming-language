/*
Exercise 1-14. Write a program to print a histogram of the frequencies of different characters
in its input.
*/

#include <stdio.h>

#define SKIP_SPACE 1                         /* 1 if you don't want to count space, 0 if you do */
#define MIN_CHAR 32 + SKIP_SPACE             /* minimum printable ascii code */
#define MAX_CHAR 126                         /* maximum printable ascii code */
#define CHAR_COUNT (MAX_CHAR - MIN_CHAR + 1) /* number of printable characters*/
#define MARKER '*'                           /* histogram marker*/

void print_vertical_histogram(int freq[]);
void print_horizontal_histogram(int freq[]);

int main(void)
{
    int freq[MAX_CHAR + 1] = {0};
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c >= MIN_CHAR && c <= MAX_CHAR)
            freq[c]++;
    }

    print_vertical_histogram(freq);
}

int num_digits(int n)
{
    int digits = 0;
    do
    {
        digits++;
        n /= 10;
    } while (n != 0);
    return digits;
}

void print_vertical_histogram(int freq[])
{
    // Find the max freq (the histogram's height)
    int max_element = 0;
    for (int i = MIN_CHAR; i <= MAX_CHAR; i++)
    {
        if (freq[i] > max_element)
            max_element = freq[i];
    }
    int max_width = num_digits(max_element);

    // Print the histogram
    for (int i = max_element; i > 0; i--)
    {
        printf("%-*d ", max_width, i);
        for (int j = MIN_CHAR; j <= MAX_CHAR; j++)
        {
            printf("%c ", (freq[j] >= i) ? MARKER : ' ');
        }
        putchar('\n');
    }

    // The final number row
    printf("%-*d ", max_width, 0);
    for (int i = MIN_CHAR; i <= MAX_CHAR; i++)
    {
        printf("%c ", i);
    }
    putchar('\n');
}

void print_horizontal_histogram(int word_count[])
{
    printf("maybe later\n");
}