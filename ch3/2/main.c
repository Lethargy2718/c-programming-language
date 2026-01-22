/*
Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write
a function for the other direction as well, converting escape sequences into the real characters.
*/

#include <stdio.h>

#define MAXLINE 100

int escape(char s[], char t[]);
int unescape(char s[], char t[]);

int main(void)
{
    char t[MAXLINE + 1] = "hello\tworld\n";
    char s[MAXLINE + 1];

    char t2[MAXLINE + 1] = "hello\\tworld\\n";
    char s2[MAXLINE + 1];

    escape(s, t);
    unescape(s2, t2);

    printf("%s\n", s);
    printf("----\n");
    printf("%s\n", s2);
    return 0;
}

int escape(char s[], char t[])
{
    int i = 0, j = 0;
    while (t[j] != '\0' && i < MAXLINE)
    {
        switch (t[j])
        {
        case '\n':
            s[i] = '\\';
            if (i + 1 < MAXLINE)
                s[++i] = 'n';
            break;
        case '\t':
            s[i] = '\\';
            if (i + 1 < MAXLINE)
                s[++i] = 't';
            break;
        default:
            s[i] = t[j];
            break;
        }

        i++;
        j++;
    }

    s[i++] = '\0';
    return i;
}

int unescape(char s[], char t[])
{
    int i = 0, j = 0;
    while (t[j] != '\0' && i < MAXLINE)
    {
        switch (t[j])
        {
        case '\\':
            switch (t[j + 1])
            {
            case '\0':
                break;
            case 'n':
                s[i] = '\n';
                j++;
                break;
            case 't':
                s[i] = '\t';
                j++;
                break;
            default:
                s[i] = t[j];
                break;
            }
            break;
        default:
            s[i] = t[j];
            break;
        }

        i++;
        j++;
    }

    s[i++] = '\0';
    return i;
}