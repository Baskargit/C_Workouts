// https://practice.geeksforgeeks.org/problems/mr-modulo-and-pairs/0/

#include<stdio.h>

int main()
{
    int n,k,counter = 0;
    scanf("%d%d",&n,&k);

    int array[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&array[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] % array[j] == k || array[j] % array[i] == k)
            {
                ++counter;
            }        
        }
    }
    
    printf("%d\n",counter);
    return 0;
}
