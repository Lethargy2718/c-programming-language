/*
Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either
case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
that a leading or trailing - is taken literally.
*/

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

int expand(char s1[], char s2[]);

int main(void)
{
    char s1[MAXLINE + 1] = "a-Z-A";
    char s2[MAXLINE + 1];

    expand(s1, s2);
    printf("%s\n", s2);

    return 0;
}

int expand(char s1[], char s2[])
{
    int i = 0, j = 0;

    while (s1[i] != '\0' && j < MAXLINE)
    {
        s2[j] = s1[i];
        if (s1[i + 1] == '-')
        {
            int alpha = isalpha(s1[i]) && isalpha(s1[i + 2]);
            int same_case = (isupper(s1[i]) && isupper(s1[i + 2])) || (islower(s1[i]) && islower(s1[i + 2]));
            int digits = isdigit(s1[i]) && isdigit(s1[i + 2]);

            if ((alpha && same_case) || digits)
            {
                int mul = s1[i] < s1[i + 2] ? 1 : -1;

                while (s2[j] != s1[i + 2] && j < MAXLINE)
                {
                    s2[j + 1] = s2[j] + mul;
                    j++;
                }
                i++;
                j--;
            }
        }

        i++;
        j++;
    }

    s2[j++] = '\0';
    return j; // length including \0
}
