#include <stdio.h>

int mhtoi(char s[]);

main()
{
int a;
a = mhtoi("0x5a5");
printf("%d", a);
return 0;

}

int mhtoi(char s[])
{
    int i, n;
    i = n = 0;
    
    if (s[1] == 'x' || s[1] == 'X')
        i = 2;
    for (;s[i] != '\0'; i++) {
        if (s[i] >= 'a')
            n = n * 16 + s[i] - 'a' + 10;
        else if (s[i] >= 'A')
            n = n * 16 + s[i] - 'A' + 10;
        else
            n = n * 16 + s[i] - '0';
    }

    return n;
}