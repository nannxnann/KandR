#include <stdio.h>

main()
{
    int  a,b, c;
    
    b = c = 1;
    a = 2;
    (a=3), c+=a, b+=c;
    printf("%d", a);
    return 0; 
}