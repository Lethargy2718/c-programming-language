/*
Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
(The standard library function strpbrk does the same job but returns a pointer to the
location.)
*/

#include <stdio.h>

#define UNDEFINED -1

int any_while(char s1[], char s2[]);
int any_for(char s1[], char s2[]);

int main(void)
{
    char s1[] = "aaaabcaaaaac\0";
    char s2[] = "b\0";
    printf("%d\n", any_while(s1, s2));
    printf("%d\n", any_for(s1, s2));
    return 0;
}

int any_while(char s1[], char s2[])
{
    int i = 0;
    while (s1[i] != '\0')
    {
        int j = 0;
        while (s2[j] != '\0')
        {
            if (s1[i] == s2[j++])
                return i;
        }
        i++;
    }
    return -1;
}

int any_for(char s1[], char s2[])
{
    for (int i = 0; s1[i] != '\0'; i++)
    {
        for (int j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
            {
                return i;
            }
        }
    }
    return -1;
}