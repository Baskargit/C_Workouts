#include <stdio.h>

void printArray(int *arr,int size);

void InsertionSort(int *arr,int size);


int main()
{
    int arr[5] = {3,5,1,4,2};

    printArray(arr,sizeof(arr)/sizeof(int));

    InsertionSort(arr,sizeof(arr)/sizeof(int));

    printArray(arr,sizeof(arr)/sizeof(int));

    return 0;
}

void printArray(int *arr,int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
}

void InsertionSort(int *arr,int size)
{
    // 1.Select a data element
    // 2.Place the data element in the proper position of sub-array

    printf("\n");

    for (int i = 1; i < size; i++)
    {
        int un_sorted_element = arr[i],j;
        j = i;

        while (j > 0 && arr[j-1] > un_sorted_element)
        {
            arr[j] = arr[j-1];
            j--;
        }

        arr[j] = un_sorted_element;
        printArray(arr,size);
    }


    printf("\n");
    
}


