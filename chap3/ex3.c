#include <stdio.h>

void expand(char s1[], char s2[]);

main()
{
    char a[100] = "--88a-e990-5A-C-a-Z";
    char b[100];
    expand(a, b);
    printf("%s", b);
}

void expand(char s1[], char s2[])
{
    int i, j;
    for (i = j = 0; s1[i] != '\0'; i++) {

        if (s1[i] == '-' && i != 0) {
            if (s1[i-1] <= 'z' && s1[i-1] >= 'a' && s1[i+1] <= 'z' && s1[i+1] >= 'a') {
                for (char k = s1[i-1] + 1; k <= s1[i+1]; s2[j++] = k, ++k) 
                    ;
                i += 1;
            }
            else if (s1[i-1] <= 'Z' && s1[i-1] >= 'A' && s1[i+1] <= 'Z' && s1[i+1] >= 'A') {
                for (char k = s1[i-1] + 1; k <= s1[i+1]; s2[j++] = k, ++k) 
                    ;
                i += 1;
            }
            else if (s1[i-1] <= '9' && s1[i-1] >= '0' && s1[i+1] <= '9' && s1[i+1] >= '0') {
                for (char k = s1[i-1] + 1; k <= s1[i+1]; s2[j++] = k, ++k) 
                    ;
                i += 1;
            }
            else
                s2[j++] = s1[i];
            
        }
        else
            s2[j++] = s1[i];
    }
    s2[j] = '\0';
}