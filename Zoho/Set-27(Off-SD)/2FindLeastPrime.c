#include <stdio.h>

int main()
{
    int n = 2;
    int arr1[] = {20,7,11,4};
    int arr2[] = {11,5,11,4};

    int leastprimes[sizeof(arr1)/sizeof(arr1[0])];

    int primes[1000],primecounter = 1;
    primes[0] = 1;

    for (int i = 2; i <= 1000; i++)
    {
        int flag = 1;

        for (int j = 2; j < i; j++)
        {
            if(i % j == 0) {
                flag = 0;
                break;
            }
        }

        if(flag) {
            primes[primecounter++] = i;
        }
    }

    // for (int i = 0; i < primecounter; i++)
    // {
    //     printf("%d ",primes[i]);
    // }

    for (int i = 0; i < sizeof(arr1)/sizeof(int); i++)
    {
        int num = -1;

        for (int j = 0; j < primecounter; j++)
        {
            if((arr1[i] + primes[j]) % arr2[i] == 0) {
                num = primes[j];
                break;
            }    
        }

        printf("%d ",num);
    }

    printf("\n");
    
    
    
    return 0;
}
