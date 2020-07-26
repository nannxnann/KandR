#include <stdio.h>
#include<string.h>
#define MAX 100
void reverse(char s[], int start, int end);
int main()
{
    char a[MAX] = "hexlo0";
    int len = strlen(a);
    reverse(a, 0, len-1);
    printf("string = %s\n", a);
    return 0;
}

void reverse(char s[], int start, int end)
{
    if (start >= end)
        return ;
    reverse(s, start+1, end-1);
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
}
