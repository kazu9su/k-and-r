#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 1000

double atof(char s[]);

int main()
{
    {
        char s[MAXLINE] = "123.00";
        double expected = atof(s);

        printf("%f\n", expected);
        assert(123.00 == expected);
    }

    {
        char s[MAXLINE] = "-123.00";
        double expected = atof(s);

        printf("%f\n", expected);
        assert(-123.00 == expected);
    }

    {
        char s[MAXLINE] = "123.45e-6";
        double expected = atof(s);

        printf("%f\n", expected);
        assert(123.45e-6 == expected); //doubleの有効桁は7桁
    }

    {
        char s[MAXLINE] = "123.45E+3";
        double expected = atof(s);

        printf("%f\n", expected);
        assert(123.45E+3 == expected); //doubleの有効桁は7桁
    }

    return 0;
}

double atof(char s[])
{
    double val, power, exp, j;
    int i, sign, exp_sign;

    for (i=0; isspace(s[i]); i++) {}

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (val=0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    if (s[i] == 'e' || s[i] == 'E') {
        i++;

        exp_sign = s[i++] == '+' ? 1 : -1;

        for (exp=0.0; isdigit(s[i]); i++) {
            exp = 10.0 * exp + (s[i] - '0');
        }
    }

    return sign * val / power * pow(10.0, exp_sign * exp);
}
