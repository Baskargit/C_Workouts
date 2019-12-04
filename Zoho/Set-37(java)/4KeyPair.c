/*
Given an array A of N positive integers and another number X. 
Determine whether or not there exist two elements in A whose sum is exactly X.

Input:
2
6 16
1 4 45 6 10 8
5 10
1 2 4 3 6

Output:
Yes
Yes

Explanation:
Testcases 1: 10 and 6 are numbers making a pair whose sum is equal to 16.
*/

#include <stdio.h>
#include <stdbool.h>

bool iskeypairfound(int *arr,int size,int sum)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                return true;
            }
            
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == sum) {
            return true;
        }
    }
    
    return false;
}

int main()
{
    int n = 6 , x = 16;
    int arr[] = {1,4,45,6,10,8};

    printf("%s\n",iskeypairfound(arr,n,x) ? "Yes" : "No");
    return 0;
}

