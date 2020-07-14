#include <stdio.h>

int escape(char s[], char t[])
{
    int i,j;
    for (i = j = 0; t[i] != '\0'; i++, j++) {
        switch (t[i]) {
            case '\n': 
                s[j++] = '\\';
                s[j] = 'n';
                break; 
            case '\t':
                s[j++] = '\\';
                s[j] = 't';
                break;
            default:
                s[j] = t[i];
                break; 
        }
    }
    s[j] = '\0';
    return 0;
}

int reverse(char s[], char t[])
{
    int i,j;
    for (i = j = 0; t[i] != '\0'; i++, j++) {
        if (t[i] == '\\') {
            switch (t[++i]) {
                case 'n': 
                    s[j] = '\n';
                    break; 
                case 't':
                    s[j] = '\t';
                    break;
                default:
                    --i;
                    break; 
            }
        }
        else
            s[j] = t[i];
    }
    s[j] = '\0';
    return 0;
}

main()
{
    char a[20] = "hello\nme\ttest";
    char b[20];
    char c[20];
    escape(b,a);
    reverse(c,b);
    printf("%s\n", a);
    printf("%s\n", b);
    printf("%s\n", c);
    return 0;
}