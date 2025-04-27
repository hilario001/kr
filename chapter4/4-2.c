/* Exercise 4-2. Extend atof to handle scientific notation of the form 123.45e-6
where a floating-point number may be followed by e or E and an optionally signed
exponent. */

#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main()
{
        printf("%g\n", atof("123.45e-6"));
        printf("%g\n", atof("10e2"));
        printf("%g\n", atof("10.1e-1"));
        printf("%g\n", atof("7.1e2"));
        printf("%g\n", atof("7.e-"));
        printf("%g\n", atof("8.1"));

        return 0;
}

double atof(char s[])
{
        double val, power;
        int i, j, sign;
        double exponent = 1.0;  // value of exponent
        int positive_exponent;  // if exponent is positive i.e. 10e+2 or not

        for (i = 0; isspace(s[i]); ++i)
                ;

        sign = (s[i] == '-') ? -1 : 1;

        if (s[i] == '+' || s[i] == '-')
                ++i;

        for (val = 0.0; isdigit(s[i]); ++i)
                val = 10.0 * val + (s[i] - '0');

        if (s[i] == '.')
                ++i;

        for (power = 1.0; isdigit(s[i]); ++i) {
                val = 10.0 * val + (s[i] - '0');
                power *= 10;
        }

        if (s[i] == 'e' || s[i] == 'E')
                ++i;

        positive_exponent = (s[i] == '-') ? 0 : 1;

        if (s[i] == '+' || s[i] == '-')
                ++i;

        for (j = 0; isdigit(s[i]); ++i)
                j = 10 * j + (s[i] - '0');

        for (; j > 0; --j)
                exponent *= 10;

        if (positive_exponent)
                return sign * val / power * exponent;

        return sign * val / power / exponent;
}
