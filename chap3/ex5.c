#include <stdio.h>

void itob(int n, char s[], int b);
void reverse(char s[]);
main()
{
    int number = 15864;
    char str[50];
    int base = 16;
    itob(number, str, base);
    printf("%s", str);
    return 0;
}

void itob(int n, char s[],int b)
{
    int i, sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        if(n % b > 9)
            s[i++] = n % b -10 + 'A';
        else
            s[i++] = n % b + '0';
    } while ((n /= b) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int i, length, temp;
    for (length = 0; s[length+1] != '\0'; length++)
        ;
    for (i = 0; i < length; ++i, --length) {
        temp = s[i], s[i] = s[length], s[length] = temp;
    }
    return;
}