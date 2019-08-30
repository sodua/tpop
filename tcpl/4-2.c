/* Extend atof to handle scientific notation of the form 123.45e-6 where a
 * floating-point number may be followed by e or E and an optionally signed exponent.
 */

#include <ctype.h>
#include <stdio.h>

/* atof:    convert string s to double */
double atof(char s[])
{
    double val, power, result, eresult;
    int i, sign, epower, eval;

    for (i = 0; isspace(s[i]); i++)     /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    result = sign * val / power;
	if (s[i] == 'E' || s[i] == 'e') {
		i++;
        sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (eval = 0; isdigit(s[i]); i++)
            eval = 10 * eval + (s[i] - '0');
        for (i = 1; i < eval; i++)
            result *= val;
        if (sign == -1)
            result = 1 / result;
    }
    return result;
}
