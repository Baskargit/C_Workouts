#include <stdio.h>
#include <math.h>

int main()
{
    int n = 182;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n/i == i) {
                printf("%d ",i);
            } else {
                printf("%d %d ",i,n/i);
            }
        }
        
    }
    printf("\n");
    
    return 0;
}
