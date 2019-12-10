#include <stdio.h>

int main()
{
    int n = 130;

    int i = 120;
    while (i <= n)
    {
        int rem = i % 10;

        if(rem == 0 || rem == 1) 
        {
            int quo = i;

            if(quo == 0 || quo == 1 || quo == 10 || quo == 11) {
                printf("%d ",i);
            }
        }
        i++;
    }
    printf("\n");

    return 0;
}