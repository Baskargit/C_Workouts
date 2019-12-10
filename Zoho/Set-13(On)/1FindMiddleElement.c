/*
Given an unsorted array of size N. Find the first element in array such that all of its left elements 
are smaller and all right elements to it are greater than it.

Input
4
4 2 5 7
3
11 9 12
6
4 3 2 7 8 9

Output:
5
-1
7
*/

// Inefficient Soln
// #include <stdio.h>

// int main()
// {
//     int n;
//     scanf("%d",&n);

//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d",&arr[i]);
//     }
    
//     int midelement = -1;

//     for (int i = 0; i < n - 1; i++)
//     {
//         int left = 1 , right = 1;

//         for (int j = 0; j < i; j++)
//         {
//             if(arr[j] >= arr[i]) {
//                 left = 0;
//                 break;
//             }
//         }

//         for (int k = i + 1; k < n; k++)
//         {
//             if(arr[k] <= arr[i]) {
//                 right = 0;
//                 break;
//             }
//         }
        
//         if(left && right) {
//             midelement = arr[i];
//             break;
//         }
        
//     }
    
//     printf("%d\n",midelement);
//     return 0;
// }

// Efficient Soln (Own approach)
// Accepted answer in Geeks for Geeks
// It couldn't handle duplicate numbers
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
    
    int midelement = -1;
    int max = arr[0],maxindex = 0;


    for (int i = 0; i < n - 1; i++)
    {
        if(arr[i] >= max && i != maxindex) 
        {
            int true = 1;

            for (int j = i+1; j < n; j++)
            {
                if(arr[j] < arr[i]) {  true = 0; break; } 
            }

            if(true) {
                midelement = arr[i];
                break;
            }
            max = arr[i];
            maxindex = i;
        }
    }
    
    printf("%d\n",midelement);
    return 0;
}

/*
Input:
16
37 40  22 13 28 41 10 14 27 41 42 43 47 48 49 50

Its Correct output is:
41

And Your Code's output is:
42
*/
