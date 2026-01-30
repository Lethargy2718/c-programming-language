/*
Exercise 4-2. Extend atof to handle scientific notation of the form 123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent.
*/

#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main(void)
{
    printf("%f\n", atof("12.34e-5"));  // 0.000123
    printf("%f\n", atof("12.34e2"));   // 1234.0
    printf("%f\n", atof("12.34"));     // 12.34
    printf("%f\n", atof("-12.34e-2")); // -0.1234
    printf("%f\n", atof("1.23E+3"));   // 1230.0
    printf("%f\n", atof(".5E1"));      // 5
}

double atof(char s[])
{
    double val, exp = 1.0;
    int i, sign, exp_sign, exp_val;

    // Skip whitespace
    for (i = 0; isspace(s[i]); i++)
        ;

    // Get sign
    sign = (s[i] == '-') ? -1 : 1;

    // Skip if sign character
    if (s[i] == '+' || s[i] == '-')
        i++;

    // Get the value before the decimal point
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    // Skip decimal point
    if (s[i] == '.')
        i++;

    // Handle digits after decimal point
    while (isdigit(s[i]))
    {
        val = 10.0 * val + (s[i] - '0');
        exp /= 10;
        i++;
    }

    // Handle scientific notation
    if (s[i] == 'e' || s[i] == 'E')
    {
        // Read character after e
        i++;

        // Set exponent sign
        exp_sign = (s[i] == '-') ? -1 : 1;

        // If sign, skip to read digits
        if (!isdigit(s[i]))
            i++;

        // Read digits
        for (exp_val = 0; isdigit(s[i]); i++)
        {
            exp_val = 10 * exp_val + (s[i] - '0');
        }

        // Handle exponent
        if (exp_sign == 1)
        {
            while (exp_val--)
                exp *= 10;
        }
        else
        {
            while (exp_val--)
                exp /= 10;
        }
    }

    // There is no exponent
    return sign * val * exp;
}