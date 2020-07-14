#include <stdio.h>

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high)/2;
        if(x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if(v[high] == x)
        return high;
    else
        return  -1; 
}

main()
{
    int test[9] = {0, 1, 2, 3, 4, 5, 10, 15, 70};
    printf("result : %d\n", binsearch(70, test, 9));
    return 0;
}