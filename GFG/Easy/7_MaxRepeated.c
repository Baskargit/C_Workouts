// https://practice.geeksforgeeks.org/problems/maximum-repeating-number/0/?ref=self

#include<stdio.h>

int main()
{
    unsigned int n,k;
    scanf("%d%d",&n,&k);

    unsigned int counter[n+1],mostRepeated = 0,mostRepeatedValue = 0;
    for (unsigned int i = 0; i <= n; i++)
    {
        counter[i] = 0;
    }
    for (unsigned int i = 0; i < n; i++)
    {
        unsigned int temp;
        scanf("%d",&temp);

        if (counter[temp])
        {
            counter[temp] += 1;
        }
        else
        {
            counter[temp] = 1;
        }
    }

    for (unsigned int i = 0; i <= n; i++)
    {
        if (counter[i] > mostRepeatedValue)
        {
            mostRepeated = i;
            mostRepeatedValue = counter[i];
        }        
    }
    
    printf("%d\n",mostRepeated);
    return 0;
}
