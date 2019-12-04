/*
link : https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

Given a set of non-negative integers, and a value sum, 
determine if there is a subset of the given set with sum equal to given sum.
*/

// iterative approach
#include <stdio.h>

int main()
{
    int n = 6;
    int arr[] = {3, 34, 4, 12, 5, 2};
    // int arr[] = {1, 2, 5, 4, 3, 6};
    int sum = 44;
    n = sizeof(arr)/sizeof(int);

    int selectedsum = 0;
    int deselectedsum = 0;
    for (int i = 0; i < n; i++)
    {
        // Select and sum remaining numbers
        selectedsum = 0;

        for (int j = i + 1; j < n; j++)
        {
            selectedsum = 0;

            for (int j1 = i; j1 < j; j1++)
            {
                selectedsum += arr[j1];
            }
            
            for (int k = j; k < n; k++)
            {
                if (selectedsum + arr[k] == sum)
                {
                    for (int print = i; print < j; print++)
                    {
                        printf("%d ",arr[print]);
                    }
                    printf("%d\n",arr[k]);
                } 
            }
        }

        // Deselect and sum remaining numbers
        deselectedsum = 0;

        for (int l = i+1; l < n; l++)
        {
            deselectedsum = 0;
            deselectedsum += arr[i];

            for (int l1 = l+1; l1 < n; l1++)
            {
                deselectedsum += arr[l1];

                if (deselectedsum == sum)
                {
                    printf("%d ",arr[i]);
                    for (int l2 = l + 1; l2 <= l1; l2++)
                    {
                        printf("%d ",arr[l2]);
                    }
                    printf("\n");
                }
                
            }
            
        }
        
    }
    
    return 0;
}
