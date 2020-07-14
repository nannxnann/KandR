#include <stdio.h>

void squeze(char s1[], char s2[]);

main()
{
    char s1[50] = "hello world!";
    char s2[50] = "elo";
    squeze(s1,s2);
    printf("%s", s1);
    return 0;
}

void squeze(char s1[], char s2[])
{
    int k, state; //state means if match happened.
    k = state = 0;
    for (int i = 0; s1[i] != '\0'; i++, state = 0) {
        for (int j = 0; s2[j] != '\0'; j++)
            if(s1[i] == s2[j])
                state = 1;
        if (!state)
            s1[k++] = s1[i];
    }
    s1[k] = '\0';
}