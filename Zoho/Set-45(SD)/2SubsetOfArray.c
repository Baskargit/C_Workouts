/*

Print all the possible subsets of array which adds up to give a sum.

Input: 
array = {2, 3, 5, 8, 10}
sum=10

Output: 
{2, 3, 5}
{2, 8}
{10}

*/

#include<stdio.h>
#include<stdbool.h>

void printSubsets(int n,int array[n],int totalSum,int currentN,int currentSum);
bool printSubsets1(int n,int array[n],int totalSum,int currentN,int currentSum);
bool printSubsets2(int n,int array[n],int totalSum,int currentN,int currentSum,int tempSubSet[n],int tempSubSetN,int subSets[n][n],int *totalSubSetCount);
void printfSubsets(int n,int subsetCount, int subSets[subsetCount][n+1]);

static int callCount = 0;

int main()
{
    int n;
    // int array[] = {2,3,5,8,10,5,2};
    int array[] = {1,2,3,4,5};
    n = sizeof(array)/sizeof(int);
    int sum = 10;

    int tempSubSet[n];
    int subSets[n][n + 1];
    int subsetCount = 0;

    // printSubsets(n,array,sum,0,0);
    // printSubsets1(n,array,sum,0,0);
    printSubsets2(n,array,sum,0,0,tempSubSet,0,subSets,&subsetCount);
    printf("\n");
    // printf("Total subset count : %d\n",subsetCount);
    // printf("callCount : %d\n",callCount);

    // printfSubsets(n,subsetCount,subSets);
    return 0;
}

bool printSubsets2(int n,int array[n],int totalSum,int currentN,int currentSum,int tempSubSet[n],int tempSubSetN,int subSets[n][n],int *totalSubSetCount)
{
    ++callCount;

    if (currentN < n)
    {
        if (array[currentN] + currentSum == totalSum)
        {
            tempSubSet[tempSubSetN] = array[currentN];

            // print
            printf("\n{");
            for (int i = 0; i < tempSubSetN + 1; i++)
            {
                printf("%d,",tempSubSet[i]);
            }
            printf("}");
            
            *totalSubSetCount += 1;
            return true;
        }
        else if (array[currentN] + currentSum < totalSum)
        {
            tempSubSet[tempSubSetN] = array[currentN];

            // Included
            printSubsets2(n,array,totalSum,currentN+1,currentSum+array[currentN],tempSubSet,tempSubSetN+1,subSets,totalSubSetCount);
            
            // Not-included
            return printSubsets2(n,array,totalSum,currentN+1,currentSum,tempSubSet,tempSubSetN,subSets,totalSubSetCount);
        }
        else
        {
            // Not-included but call next n+1
            return printSubsets2(n,array,totalSum,currentN+1,currentSum,tempSubSet,tempSubSetN,subSets,totalSubSetCount);
        }
    }
    else
    {
        return false;
    }
}

void printfSubsets(int n,int subsetCount, int subSets[subsetCount][n+1])
{
    printf("\n");
    for (int i = 0; i < subsetCount; i++)
    {
        printf("{");
        for (int j = 1; j <= (subSets[i][0] >= 0 && subSets[i][0] <= n) ? subSets[i][0] : 0; j++)
        {
            printf("%d,",subSets[i][j]);
        }
        printf("}");
    }
    printf("\n");
}

bool printSubsets1(int n,int array[n],int totalSum,int currentN,int currentSum)
{
    // printf("callCount : %d\n",++callCount);

    if (currentN < n)
    {
        if (array[currentN] + currentSum == totalSum)
        {
            printf("%d ",array[currentN]);
            return true;
        }
        else if (array[currentN] + currentSum < totalSum)
        {
            if (printSubsets1(n,array,totalSum,currentN + 1,currentSum + array[currentN])) // Included
            {
                printf("%d,",array[currentN]);
            }
            
            printSubsets1(n,array,totalSum,currentN + 1,currentSum); // Not-included
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void printSubsets(int n,int array[n],int totalSum,int currentN,int currentSum)
{
    if (currentN < n)
    {
        if (array[currentN] + currentSum == totalSum)
        {
            printf("Found\n");
            return;
        }
        else if (array[currentN] + currentSum < totalSum)
        {
            printSubsets(n,array,totalSum,currentN + 1,currentSum + array[currentN]); // Included
            printSubsets(n,array,totalSum,currentN + 1,currentSum); // Not-included
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }
    
}

