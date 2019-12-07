// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence/0

/*
7
2 6 1 9 4 5 3
7
1 9 3 10 4 20 2

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

    // Bubble sort
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if(arr[j] < arr[i]) {
    //             int temp = arr[j];
    //             arr[j] = arr[i];
    //             arr[i] = temp;
    //         }
    //     }
    // }

    // Insertion sort
    for (int i = 1; i < n; i++)
    {
        int un_sorted_element = arr[i],j;
        j = i;

        while (j > 0 && arr[j-1] > un_sorted_element)
        {
            arr[j] = arr[j-1];
            j--;
        }

        arr[j] = un_sorted_element;
    }

    int maxsequence = 1;

    for (int i = 0; i < n;)
    {
        int currentsequence = 1;

        int j = i + 1;
        while (j < n && arr[j] - arr[j - 1] == 1)
        {
            currentsequence++;
            j++;
        }
        // printf("breaked in i = %d and j = %d and currentsequence = %d\n",i,j,currentsequence);

        if(arr[j] - arr[j - 1] == 0) 
        {
            currentsequence++;
            while (arr[j] == arr[j+1])
            {
                currentsequence++;
                j++;
            }
            
        }

        maxsequence = (currentsequence > maxsequence) ? currentsequence  : maxsequence;
        
        i = j;
    }
    
    printf("%d\n",maxsequence);
    
    return 0;
}

/*
corner case
4
1 2 2 3

Normal cases:
7
2 6 1 9 4 5 3

7
1 9 3 10 4 20 2

5
1 2 2 3 4
*/
