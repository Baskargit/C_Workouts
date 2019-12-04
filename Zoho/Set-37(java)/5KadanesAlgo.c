/*
Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

Input
2
5
1 2 3 -2 5
4
-1 -2 -3 -4
Output
9
-1

Explanation:
Testcase 1: Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.

*/

#include <stdio.h>

// int main()
// {
//     int n = 5;
//     int arr[] = {-1,-2,-3,-4};
//     // int arr[] = {1,2,3,-2,5};

//     int maxsum = 0;
//     int tempsum;
//     for (int i = 0; i < n; i++)
//     {
//         tempsum = 0;
//         tempsum += arr[i];

//         for (int j = i+1; j < n; j++)
//         {
//             tempsum += arr[j];

//             if (tempsum > maxsum)
//             {
//                 maxsum = tempsum;
//             }
//         }
//     }

//     if (maxsum == 0)
//     {
//         maxsum = arr[0];

//         for (int i = 1; i < n; i++)
//         {
//             maxsum = (arr[i] > maxsum) ? arr[i] : maxsum;
//         }
//     }
    

//     printf("%d\n",maxsum);
    
//     return 0;
// }

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    

    int max_so_far = arr[0];
    int max_ending_here = 0;

    for (int i = 0; i < n; i++)
    {
        max_ending_here += arr[i];

        if (max_ending_here < 0)  {
            max_ending_here = 0;
        } 
        else if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
    }
    
    

    printf("%d\n",max_so_far);
    
    return 0;
}
