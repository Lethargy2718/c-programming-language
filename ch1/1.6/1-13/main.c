/*
Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
*/

#include <stdio.h>

#define MAX_SIZE 10 /* max word size*/
#define MARKER '*'  /* histogram marker*/

void print_vertical_histogram(int word_count[]);
void print_horizontal_histogram(int word_count[]);

int main(void)
{
    int word_count[MAX_SIZE + 1] = {0};
    int c, l;
    l = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (l > 0 && l <= MAX_SIZE)
                word_count[l]++;

            l = 0;
            continue;
        }
        l++;
    }

    // In case the last word isn't followed by whitespace
    if (l > 0 && l <= MAX_SIZE)
        word_count[l]++;

    print_vertical_histogram(word_count);
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

void print_vertical_histogram(int word_count[])
{
    // Find the max element (the histogram's height)
    int max_element = 0;
    for (int i = 1; i <= MAX_SIZE; i++)
    {
        if (word_count[i] > max_element)
            max_element = word_count[i];
    }
    int max_width = num_digits(max_element);

    // Print the histogram
    for (int i = max_element; i > 0; i--)
    {
        printf("%-*d ", max_width, i);
        for (int j = 1; j <= MAX_SIZE; j++)
        {
            putchar((word_count[j] >= i) ? MARKER : ' ');
            putchar(' ');
        }
        putchar('\n');
    }

    // The final number row
    printf("%-*d ", max_width, 0);
    for (int i = 1; i <= MAX_SIZE; i++)
    {
        printf("%d ", i);
    }
    putchar('\n');
}

void print_horizontal_histogram(int word_count[])
{
    printf("maybe later\n");
}