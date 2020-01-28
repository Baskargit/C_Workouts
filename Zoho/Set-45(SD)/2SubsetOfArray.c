/*

Print all the possible subsets of array which adds up to give a sum.

https://www.geeksforgeeks.org/perfect-sum-problem-print-subsets-given-sum/

Input: 
array = {2, 3, 5, 8, 10}
sum=10

Output: 
{2, 3, 5}
{2, 8}
{10}

*/

// Working soln

#include<stdio.h>

int getSubsetsCount(int n,int array[n],int totalSum,int currentN,int currentSum,int tempSubSet[n],int tempSubSetN);

static int callCount = 0;

int main()
{
    int n;
    // int array[] = {2,3,5,8,10,5,2}; // 10
    // int array[] = {1,2,3,4,5}; // 10
    // int array[] = {2,23,12,12,19,18,5,8,6,13,24,18,11,5,3,23}; // 59
    int array[] = { 2, 0, 5, 7, -1, 0, 8, 4, 1, 3, -2, 0, 0, 2, -2 }; // 22
    n = sizeof(array)/sizeof(int);
    int sum = 22;

    int tempSubSet[n]; // store subsets temporarily
    int subsetCount = getSubsetsCount(n,array,sum,0,0,tempSubSet,0); // get total possible subSets

    printf("\nTotal subset count : %d\n",subsetCount);
    printf("callCount : %d\n",callCount);

    return 0;
}

int getSubsetsCount(int n,int array[n],int totalSum,int currentN,int currentSum,int tempSubSet[n],int tempSubSetN)
{
    ++callCount;

    if (currentN < n)
    {
        if (array[currentN] + currentSum == totalSum)
        {
            // Print the subsets
            printf("\n{");
            for (int i = 0; i < tempSubSetN; i++)
            {
                printf("%d,",tempSubSet[i]);
            }
            printf("%d}",array[currentN]);

            return 1 + getSubsetsCount(n,array,totalSum,currentN+1,currentSum,tempSubSet,tempSubSetN);
        }
        else if (array[currentN] + currentSum < totalSum)
        {
            tempSubSet[tempSubSetN] = array[currentN];

            // Included + Not-included
            return getSubsetsCount(n,array,totalSum,currentN+1,currentSum+array[currentN],tempSubSet,tempSubSetN+1) + getSubsetsCount(n,array,totalSum,currentN+1,currentSum,tempSubSet,tempSubSetN);
        }
        else
        {
            // else { array[currentN] + currentSum > totalSum } , so call next element
            // Not-included but call next n+1
            return getSubsetsCount(n,array,totalSum,currentN+1,currentSum,tempSubSet,tempSubSetN);
        }
    }
    else
    {
        return 0;
    }
}

/*
Corner cases :

Input:
16
2 23 12 12 19 18 5 8 6 13 24 18 11 5 3 23
59

Its Correct output is:
335

And Your Code's output is:
331

*/