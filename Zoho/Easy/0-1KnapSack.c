/*

https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0

You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

Input:
The first line consists of N the number of items.
The second line consists of W, the maximum capacity of the knapsack.
In the next line are N space separated positive integers denoting the values of the N items,
and in the fourth line are N space separated positive integers denoting the weights of the corresponding items.

Output:
For each testcase, in a new line, print the maximum possible value you can get with the given conditions that you can obtain for each test case in a new line.
*/

#include<stdio.h>
#include<stdlib.h>

void findMaxValue(int n,int maxCapacity,int values[n],int weights[n],int *maxValue,int currentN,int currentVal,int currentWt);

static int recursioncount = 0;

int main()
{
    int n;
    scanf("%d",&n);
    int maxCapacity;
    scanf("%d",&maxCapacity);

    int values[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&values[i]);
    }

    int weights[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&weights[i]);
    }

    int maxValue = 0;
    findMaxValue(n,maxCapacity,values,weights,&maxValue,0,0,0);
    printf("Max Val : %d\n",maxValue);
    printf("Recursioncount %d\n",recursioncount);
    return 0;
}

void findMaxValue(int n,int maxCapacity,int values[n],int weights[n],int *maxValue,int currentN,int currentVal,int currentWt)
{
    recursioncount++;

    if (currentN < n)
    {
        if (currentWt + weights[currentN] < maxCapacity)
        {
            // Include
            findMaxValue(n,maxCapacity,values,weights,maxValue,currentN+1,currentVal+values[currentN],currentWt+weights[currentN]);
        }
        else // Greater (or) equal
        {            
            *maxValue = (currentWt + weights[currentN] == maxCapacity && currentVal+values[currentN] > *maxValue) 
                        ? currentVal + values[currentN] 
                        : *maxValue;
        }
        // Not Include
        findMaxValue(n,maxCapacity,values,weights,maxValue,currentN+1,currentVal,currentWt);
    }
    else
    {
        *maxValue = (currentVal > *maxValue) ? currentVal : *maxValue;
        return;
    }
}

/*

Input
3
4
1 2 3
4 5 1
Output
3

Input
3
3
1 2 3
4 5 6
Output
0

Input:
58
41
57 95 13 29 1 99 34 77 61 23 24 70 73 88 33 61 43 5 41 63 8 67 20 72 98 59 46 58 64 94 97 70 46 81 42 7 1 52 20 54 81 3 73 78 81 11 41 45 18 94 24 82 9 19 59 48 2 72
83 84 85 76 13 87 2 23 33 82 79 100 88 85 91 78 83 44 4 50 11 68 90 88 73 83 46 16 7 35 76 31 40 49 65 2 18 47 55 38 75 58 86 77 96 94 82 92 10 86 54 49 65 44 77 22 81 52
Its Correct output is:
223

Input
88
71
81 28 91 49 65 97 19 75 21 88 47 10 26 67 9 39 27 85 72 64 24 14 87 7 94 100 53 1 83 71 11 87 67 39 73 49 51 44 36 60 57 97 47 2 100 77 77 35 30 42 23 18 43 10 23 52 11 80 44 8 27 90 90 93 40 96 28 60 69 34 40 13 54 74 7 82 81 20 82 5 43 69 24 55 26 49 53 98
30 12 58 32 38 59 6 4 5 8 53 17 4 75 23 41 5 39 31 60 100 60 92 12 37 82 15 47 78 74 6 86 86 35 65 69 87 89 12 97 28 33 100 33 46 47 17 80 60 23 10 49 1 62 7 77 9 49 52 41 82 95 83 79 16 11 16 54 22 96 90 3 7 80 1 56 37 23 85 59 38 45 26 76 4 52 98 75
Its Correct output is:
553

*/