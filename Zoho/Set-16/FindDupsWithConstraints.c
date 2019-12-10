#include <stdio.h> 


// function to find repeating elements 
void printRepeating( int arr[], int n) 
{ 
    // First check all the values that are 
    // present in an array then go to that 
    // values as indexes and increment by 
    // the size of array 
    for (int i = 0; i < n; i++) 
    { 
        int index = arr[i] % n; 
        arr[index] += n; 
    }

    printf("After logic\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
    printf("The repeating elements are: \n"); 
    // Now check which value exists more 
    // than once by dividing with the size 
    // of array 
    for (int i = 0; i < n; i++) 
    { 
        if ((arr[i]/n) > 1)
        {
            printf("%d ",i);
        }
    } 

    printf("\n");
} 
  
// Driver's code 
int main() 
{
    int arr[] = {1, 6, 3, 1, 3, 6, 6}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Before logic values : \n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    printRepeating( arr, arr_size); 
    return 0; 
}