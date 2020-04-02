// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating/0/

#include<stdio.h>

void printcount(unsigned int n,unsigned int count[n+1]);

int main()
{
    unsigned int n;
    scanf("%ud",&n);

    unsigned int array[n+1],count[n+1];
    for(unsigned int i = 0; i <= n; i++)
    {
        count[i] = 0;
    }
    
    for(unsigned int i = 0; i < n; i++)
    {
        unsigned int temp;
        scanf("%ud",&temp);

        array[i] = temp;
        count[temp] = (count[temp]) ? count[temp] + 1 : 1;
    }

    printcount(n,count);
    
    unsigned int missing = 0,repeated = 0;

    for(unsigned int i = 1; i <= n; i++)
    {
        if (count[i])
        {
            if (repeated)
            {
                repeated = (i < repeated) ? i : repeated;
            }
            else
            {
                repeated = (count[i] > 1) ? i : repeated;
            }
        }
        else
        {
            if (missing)
            {
                missing = (i < missing) ? i : missing;   
            }
            else
            {
                missing = i;
            }
        }
    }

    printf("%d %d\n",repeated,missing);
    return 0;
}

void printcount(unsigned int n,unsigned int count[n+1])
{
    printf("Count :\n");
    for(unsigned int i = 1; i <= n; i++)
    {
        printf("%d ",count[i]);
    }
    printf("\n");
}