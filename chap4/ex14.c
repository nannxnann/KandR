#define SWAP(t, x, y) {t temp = x; \
                       x = y;\
                       y = temp;}

#include <stdio.h>
int main()
{
    int a, b;
    a = 5;
    b = 10;
    SWAP(int, a, b)
    printf("a = %d, b = %d\n", a, b);
    return 0;
}