#include <stdio.h>

main()
{
    int c, nblank = 0, ntab = 0, nline = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++nblank;
        else if (c == '\t')
            ++ntab;
        else if (c == '\n')
            ++nline;
    }

    printf("# of blanks = %d, # of tabs = %d, # of lines = %d.\n", nblank, ntab, nline);
}