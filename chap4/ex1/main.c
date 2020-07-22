#include <stdio.h>
#define MAXLINE 1000

int mgetline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

main()
{
    char line[MAXLINE];
    int found = 0;
    int loc = 0;
    while (mgetline(line, MAXLINE) > 0)
        if((loc = strindex(line, pattern)) >= 0) {
            printf("%s right most patter's position:%d \n", line, loc);
            found++;
        }
    return found;
}



