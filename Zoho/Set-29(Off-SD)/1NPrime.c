/*
prime number – print n prime numbers
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n = 25;
    bool isprime = true;

    for (int i = 2; n >= 1; i++)
    {
        for (int j = 2; j < i; j++)
        {
            if(i % j == 0) {
                isprime = false;
                break;
            }
        }
        
        if(isprime) {
            printf("%d ",i);
            n--;
        }
        
        isprime = true;
    }

    printf("\n");
    
    return 0;
}
