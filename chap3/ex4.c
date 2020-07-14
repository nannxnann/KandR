#include <stdio.h>
/* 原版程式會有overflow的問題發生 */

void mitoa(int n, char s[]);
void reverse(char s[]);

main()
{
    // 1 word = 4 bytes.
    int test = 0x80000000;
    char str[100];
    mitoa(test,str);
    printf("%s", str);
    return 0;
}

void mitoa(int n, char s[])
{
    int i, sign;
    
    sign = n;
    i = 0;
    
    if (sign < 0) {
        do {
            s[i++] = '0' - n % 10;
        } while ((n /= 10) < 0);
        s[i++] = '-';
    }
    else
        do {
            s[i++] = n % 10 + '0';
        } while ((n /= 10) > 0);
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