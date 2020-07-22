#include <stdio.h>
/* return right most match pattern's position.*/
int strindex(char s[], char t[])
{
    int i, j, k, rMostPos;
    rMostPos = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if(k>0 && t[k] == '\0')
            rMostPos = i;
    }
    return rMostPos;
}