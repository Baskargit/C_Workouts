// https://practice.geeksforgeeks.org/problems/find-the-number-of-sub-arrays-having-even-sum/0/

#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int array[n],counter = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&array[i]);
        counter = (array[i] % 2) ? counter : counter + 1;
    }

    for (int i = 0; i < n; i++)
    {
        int sum = array[i];

        for (int j = i + 1; j < n; j++)
        {
            sum += array[j];
            counter = (sum % 2) ? counter : counter + 1;    
        }
    }
    
    printf("%d\n",counter);
    return 0;
}
