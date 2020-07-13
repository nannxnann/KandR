#include <stdio.h>

#define IN 1
#define OUT 0
/*what kind of input are most likely to uncover bugs? ans : 當一個word拆成上下兩行時
/*count lines, words, and characters in input */
main()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while((c=getchar()) != EOF) {
        ++nc;
        if (c== '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}