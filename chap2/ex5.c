#include <stdio.h>

int any(char s1[], char s2[]);

main()
{
    char s1[50] = "hello world!";
    char s2[50] = "b";
    int result = any(s1,s2);
    printf("%d", result);
    return 0;
}

int any(char s1[], char s2[])
{
    
    for (int i = 0; s1[i] != '\0'; i++)
        for (int j = 0; s2[j] != '\0'; j++)
            if(s1[i] == s2[j])
                return i;
    return -1;
    
}