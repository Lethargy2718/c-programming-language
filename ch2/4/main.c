/*
Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2.
*/

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(void)
{
    char s1[] = "abaaacaabaaac\0";
    char s2[] = "ab\0";
    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}

void squeeze(char s1[], char s2[])
{
    int r = 0;
    for (int i = 0; s1[i] != '\0'; i++)
    {
        int found = 0;
        for (int j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            s1[r++] = s1[i];
        }
    }
    s1[r] = '\0';
}