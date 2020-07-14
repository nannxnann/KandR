 #include <stdio.h>

void reverse(char s[]);
void myitoa(int n, char s[], int size);

main()
{
    int num = -157;
    char str[50];
    myitoa(num, str, 10);
    printf("%s", str);
    return 0;
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

void myitoa(int n, char s[], int size)
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    if (i-1 < size)
        for(;i < size; s[i++] = ' ')
            ;
    s[i] = '\0';
    reverse(s);
}