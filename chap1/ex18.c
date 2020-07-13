#include <stdio.h>

#define MAXLINE 1000
#define INBLANK 1
#define OUTBLANK 0

main()
{
    int i, c, countBlank, state;
    char line[MAXLINE];
    state = OUTBLANK;
    i = countBlank = 0;
    while((c = getchar()) != EOF) {
        if((line[i]=c) == '\n') {
            if(state == INBLANK) {
                line[i-countBlank] = '\0';
                printf("%s\n",line);
                ++i;
                i = 0;
                countBlank = 0;
            }
            else {
                line[i] = '\0';
                if(i != 0)
                    printf("%s\n", line);
                countBlank = 0;
                ++i;
                i = 0;
            }
            state = OUTBLANK;
            
        }
        else if((line[i]) == ' ' || (line[i]) == '\t') {
            if(state == OUTBLANK)
                state = INBLANK;
            ++countBlank;
            ++i;
        }
        else {
            state = OUTBLANK;
            countBlank = 0;
            ++i;
        }    
    }
        
    if(state == INBLANK) {
        line[i-countBlank] = '\0';
        printf("%s",line);
    }
    else {
        line[i] = '\0';
        if(i != 0)
        printf("%s", line);
    }

    return 0;
}
