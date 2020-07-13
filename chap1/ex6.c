#include <stdio.h>

/* verify the expression getchar() != is 0 or 1 */
main()
{
    int c;
    int val;
    while (val = (c = getchar()) != EOF) {
        printf("%d",val);
        putchar(c);
    }
    printf("%d",val);
}