/*
https://practice.geeksforgeeks.org/problems/shuffle-integers/0

Given an array of n elements in the following format { a1, a2, a3, a4, ….., an/2, b1, b2, b3, b4, …., bn/2 }. 
The task is shuffle the array to {a1, b1, a2, b2, a3, b3, ……, an/2, bn/2 } without using extra space.

Input:
4
1 2 9 15
6
1 2 3 4 5 6

Output:
1 9 2 15 
1 4 2 5 3 6

*/

#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int mid = n/2;

    int i = 0,till = mid;
    while (till < n)
    {
        if (i < mid)
        {
            printf("%d %d ",arr[i++],arr[till++]);
        }
        else
        {
            printf("%d ",arr[till++]);
        }
    }
    printf("\n");
    
    return 0;
}
