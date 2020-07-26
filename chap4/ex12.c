#include <stdio.h>

#define MAX 100
void printd(int n, char s[]);
int main()
{
    char a[MAX];
    printd(532, a);
    printf("%s", a);
    return 0;
}

void printd(int n, char s[])
{
    static int si = 0;
    if (n < 0) {
        s[si] = '-';
        n = -n;
        si++;
    }
    if (n / 10)
        printd(n/10, s);
    s[si++] = n % 10 + '0';
    s[si] = '\0';
}
