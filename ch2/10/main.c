/*
Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case,
with a conditional expression instead of if-else.
*/

#include <stdio.h>

char lower(char x);

int main(void)
{

    printf("%c\n", lower('G'));
    return 0;
}

char lower(char c)
{
    return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
}