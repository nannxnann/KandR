#include <stdio.h>

#define MAXLINE 1000

void reverse(char s[], int length);

main()
{
    int c, i;
    c = i = 0;
    char line[MAXLINE];
    
    //while((c = getchar()) != EOF) {
            
    //}
    for (line[i]=getchar(); line[i] != EOF ; line[i]=getchar()) {
        if(line[i] == '\n') {
            line[i+1] = '\0';
            reverse(line, c);
            printf("%s", line);
            c = 0;
            i = 0;
        }
        else {
            ++i;
            ++c;
        }
    }
    if(line[i] == EOF) {
        line[i] = '\0';
        reverse(line, c);
        printf("%s", line);
        c = 0;
        i = 0;
    }

    return 0;
}

void reverse(char s[], int length)
{
    for (int i=0; i < length/2 ; ++i) {
        char temp = s[i];
        s[i] = s[length-1-i];
        s[length-1-i] = temp;
    }
    return ;
}