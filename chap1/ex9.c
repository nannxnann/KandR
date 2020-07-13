#include <stdio.h>

main()
{
    int c;
    int isBlank = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (isBlank)
               ;
            else {
                isBlank = 1;
                putchar(c);
            }
        }
        else {
            isBlank = 0;
            putchar(c);
        }
    }
}