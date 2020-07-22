#include <stdio.h>
#include <ctype.h>

/*atof with the scientific notation implementation version*/

int myatof(char s[])
{
    double val, power;
    int i, sign, signForScienctific, valForScientific;

    for (i = 0; isspace(s[i]); i++) // skip space
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
        power *= 10;
    }
    if (s[i++] == 'e')
        signForScienctific = s[i]=='-' ? -1 : 1;
        if (s[i] == '-' || s[i] == '+')
            i++;
        for (valForScientific = 0; isdigit(s[i]); i++)
            valForScientific = valForScientific * 10 + (s[i] - '0');

    return sign * (val / power) * (float) valForScientific;
}