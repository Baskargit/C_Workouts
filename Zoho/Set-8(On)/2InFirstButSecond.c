/*
https://practice.geeksforgeeks.org/problems/in-first-but-second/0

Given two arrays A and B of positive integers. Your task is to find numbers which are present in the first array, but not present in the second array.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains space separated integers N and M which denotes the number of elements in the array A and B. Next two line contains space separated array elements.

Output:
Print space separated numbers present in the first array but not in the second.

*/

// Brutforce inefficient solution
#include<stdio.h>

int main()
{
    unsigned int n,m;
    scanf("%d%d",&n,&m);

    unsigned long long int arr1[n],arr2[m];

    for (unsigned int i = 0; i < n; i++)
    {
        scanf("%lld",&arr1[i]);
    }

    for (unsigned int i = 0; i < m; i++)
    {
        scanf("%lld",&arr2[i]);
    }

    int notfound = 1;
    for (unsigned int i = 0; i < n; i++)
    {
        notfound = 1;

        for (unsigned int j = 0; j < m; j++)
        {
            if(arr2[j] == arr1[i]) {
                notfound = 0;
                break;
            }
        }

        if(notfound) {
            printf("%d ",arr1[i]);
        }
    }

    printf("\n");
    return 0;
}
/*
6 5
1 2 3 4 5 10
2 3 1 0 5

5 5
4 3 5 9 11
4 9 3 11 10

*/
