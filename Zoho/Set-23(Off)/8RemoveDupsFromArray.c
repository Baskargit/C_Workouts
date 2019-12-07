#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    unsigned long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld",&arr[i]);
    }

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

    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if(arr[i+1] != arr[i]) 
        {
            arr[j++] = arr[i];
        }
    }

    // print the array
    for (int i = 0; i < j; i++)
    {
        printf("%lld ",arr[i]);
    }
    
    printf("\n");
    return 0;
}
