/*
Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F.
*/

#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);

int main(void)
{
    char s[] = "0xFFF\0";
    int x = htoi(s);
    printf("%d\n", x);

    return 0;
}

int htoi(char s[])
{
    int i = 0;
    if (s[0] == '\0')
        return -1;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        i = 2;
    }

    int digit, res = 0;
    while (s[i] != '\0')
    {
        if (isdigit(s[i]))
        {
            digit = s[i] - '0';
        }
        else
        {
            digit = tolower(s[i]) - 'a' + 10;
        }

        res = res * 16 + digit;
        i++;
    }
    return res;
}