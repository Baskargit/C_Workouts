/*
prime factor – sort the array based on the minimum factor they have.
*/
#include <stdio.h>

int main()
{
    int n = 7;
    // int arr[] = {5, 11, 10, 20, 9, 16, 23};
    int arr[] = {104, 210, 315, 166, 441, 180};
    n = sizeof(arr)/sizeof(int);
    int factors[n];

    // Find the factors
    for (int i = 0; i < n; i++)
    {
        int factorcount = 0;

        for (int j = 1; j <= arr[i]; j++)
        {
            if(arr[i] % j == 0) {
                factorcount++;
            }
        }

        factors[i] = factorcount;
    }

    // Print number with its factor
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d => %d\n",arr[i],factors[i]);
    // }

    // Sort in desc order based on factor weight

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (factors[i] < factors[j])
            {
                // swap factors
                int temp = factors[i];
                factors[i] = factors[j];
                factors[j] = temp;

                // swap numbers
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }   
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    printf("\n");
    return 0;
}
