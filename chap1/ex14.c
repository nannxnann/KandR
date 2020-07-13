#include <stdio.h>

main() 
{
    int c;
    int lower[26];
    int upper[26];

    for (int i = 0; i < 26; ++i)
        lower[i] = upper[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c > 'a' && c < 'z')
            ++lower[c-'a'];
        else if (c > 'A' && c < 'Z')
            ++upper[c-'A'];
    }

    for (int i = 0; i < 26; ++i){
        printf("%c ", i+'a');
        for (int j = 0; j < lower[i]; ++j)
            printf("*");
        printf("\n");
    }

    for (int i = 0; i < 26; ++i){
        printf("%c ", i+'A');
        for (int j = 0; j < upper[i]; ++j)
            printf("*");
        printf("\n");
    }


}