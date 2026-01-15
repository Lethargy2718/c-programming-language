/*
Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table.
*/

#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;   /* lower limit of temperatuire scale */
    upper = 100; /* upper limit */
    step = 10;   /* step size */
    celsius = lower;
    printf("%-8s %-6s\n", "Celsius", "Fahr");
    while (celsius <= upper)
    {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%-8.0f %-6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}