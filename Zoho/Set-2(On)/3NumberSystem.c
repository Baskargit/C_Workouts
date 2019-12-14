#include<stdio.h>

int main()
{
    int n = 100;

    unsigned long long int i = 1,j;
    int count = 0,rem;
    
    while (count <= n)
    {
        int flag = 1;

        j = i;
        while (j > 0)
        {
            rem = j % 10;

            if(rem == 3 || rem == 4)
            {
                j = j/10;
            }
            else
            {
                flag = 0;
                break;
            }
            
        }
        
        if(flag)
        {
            printf("%lld ",i);
            count++;
        }
        i++;
    }
    
    printf("\n");
    return 0;
}
