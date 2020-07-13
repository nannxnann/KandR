#include <stdio.h>

main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("celsius\tfahr\n");
    printf("-------------\n");

    celsius = lower;
    while(celsius <= upper)    {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%5.0f\t%4.0f\n",celsius,fahr);
        celsius = celsius + step;
    }
}