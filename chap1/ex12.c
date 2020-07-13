#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
    int c, nw, state;
    state = OUT;
    nw = 0;
    while((c=getchar()) != EOF) {

        if ( state == IN) 
            putchar(c);
        if (c == ' ' || c == '\n' || c == '\t')    
            state = OUT;
        else if (state == OUT) {
            state = IN;
            putchar('\n');
            putchar(c);
            ++nw;
        }
    }
}