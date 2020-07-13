#include <stdio.h>

#define MAXLINE 1000
#define THRESHOLD 80

main()
{
    int c, i;
    i = 1;
    char line[MAXLINE];
    while(i != 0) {
        line[0] = '\0';

        for (i=0; i < MAXLINE-1 && (c=getchar())!=EOF && c!='\n'; ++i)
            line[i] = c;
        if (c == '\n') {
            line[i] = c;
            ++i;
        }
        line[i] = '\0';
        if (i > THRESHOLD)
            printf("%s", line);
        if (c == EOF)
            i = 0;
        }    
        
    return 0;
}
