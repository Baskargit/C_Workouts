/*

https://practice.geeksforgeeks.org/problems/perfect-sum-problem/0

Print all the possible subsets of array which adds up to give a sum.

Input: 
array = {2, 3, 5, 8, 10}
sum=10

Output: 
{2, 3, 5}
{2, 8}
{10}

*/

// Accepted soln
// Execution Time:0.03 Sec

#include<stdio.h>

int getSubsetsCount(int n,int array[n],int totalSum,int currentN,int currentSum);

static int callCount = 0;

int main()
{
    int n;
    scanf("%d",&n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&array[i]);
    }
    int sum;
    scanf("%d",&sum);

    printf("%d\n",getSubsetsCount(n,array,sum,0,0));
    printf("Total recursive calls made : %d\n",callCount);

    return 0;
}

int getSubsetsCount(int n,int array[n],int totalSum,int currentN,int currentSum)
{
    ++callCount;

    if (currentN < n)
    {
        if (array[currentN] + currentSum == totalSum)
        {
            return 1 + getSubsetsCount(n,array,totalSum,currentN+1,currentSum);
        }
        else if (array[currentN] + currentSum < totalSum)
        {
            // Included + Not-included
            return getSubsetsCount(n,array,totalSum,currentN+1,currentSum+array[currentN]) + getSubsetsCount(n,array,totalSum,currentN+1,currentSum);
        }
        else
        {
            // else { array[currentN] + currentSum > totalSum } , so call next element
            // Not-included but call next n+1
            return getSubsetsCount(n,array,totalSum,currentN+1,currentSum);
        }
    }
    else
    {
        return 0;
    }
}


/*

Input:
16
2 23 12 12 19 18 5 8 6 13 24 18 11 5 3 23
59

Its Correct output is:
335

And Your Code's output is:
331

*/