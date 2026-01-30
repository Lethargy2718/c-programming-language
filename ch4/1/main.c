/*
Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none.
*/

#include <stdio.h>

int strindex(char s[], char t[]);

int main(void)
{
    char t[] = "ould";
    char s[] = "aould hello bould hello could hello douldd"; // last "ould" at 37
    printf("%i\n", strindex(s, t));
}

int strindex(char s[], char t[])
{
    int i, j, k, last = -1;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            last = i;
    }

    return last;
}