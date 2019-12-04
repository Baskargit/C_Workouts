/*
// link : https://practice.geeksforgeeks.org/problems/frequency-of-array-elements/0
4. Find the frequency of all numbers in an array.
Note: use dynamic memory allocation.

For example, if the input is {1, 2, 45, 67, 1, 88}, do not calculate the frequency of all elements from 1 to 88.


*/

#include<stdio.h>

// int main()
// {
// 	int testCaseCount;
//     scanf("%d",&testCaseCount);
    
//     for(int count=0; count<testCaseCount; count++)
//     {
//         int n;
//         scanf("%d",&n);
        
//         int arr[n];
//         for(int i=0; i<n; i++)
//         {
//             scanf("%d",&arr[i]);
//         }
        
//         for(int i=1; i<=n; i++)
//         {
//             int count = 0;
//             for(int j=0; j<n; j++)
//             {
//                if((arr[j] == i)) {
//                    count++;
//                }
//             }
            
//             printf("%d ",count);
//         }
//         printf("\n");
//     }
    
// 	return 0;
// }



int main()
{
	int testCaseCount;
    scanf("%d",&testCaseCount);
    
    for(int count=0; count<testCaseCount; count++)
    {
        int n;
        scanf("%d",&n);
        
        int arr[n+1];
        for (int i = 1; i < n+1; i++)
        {
            arr[i] = 0;
        }
        
        for(int i=0; i<n; i++)
        {
            int temp;
            scanf("%d",&temp);
            arr[temp]++;
        }
        
        for(int i=1; i<=n; i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    
	return 0;
}