/*
 Given an array of integers of size n. 
 Convert the array in such a way that if next valid number is same as current number, 
 double its value and replace the next number with 0. After the modification, 
 rearrange the array such that all 0’s are shifted to the end.

Input : arr[] = {2, 2, 0, 4, 0, 8}
Output : 4 4 8 0 0 0

Input : arr[] = {0, 2, 2, 2, 0, 6, 6, 0, 0, 8}
Output : 4 2 12 8 0 0 0 0 0 0
*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0 && arr[i+1] == arr[i])
        {
            arr[i] += arr[i];
            arr[i+1] = 0;
        }
    }

    int validcount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            ++validcount;
            printf("%d ",arr[i]);
        }
    }

    for (int i = validcount + 1; i <= n; i++)
    {
        printf("0%c",(i == n) ? '\0' : ' ');
    }
    
    printf("\n");
    return 0;
}
