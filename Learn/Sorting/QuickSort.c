#include <stdio.h>

void printArray(int *arr,int size);

void QuickSort(int *arr,int size);
void Partition(int *arr,int low,int high);


int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};

    printArray(arr,sizeof(arr)/sizeof(int));

    QuickSort(arr,sizeof(arr)/sizeof(int));

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

void QuickSort(int *arr,int size)
{
    Partition(arr,0,size-1);
}

void Partition(int *arr,int low,int high)
{
    printf("\n");
    int pivot = arr[low];

    int i = low ,j = high ,counter = high;

    printf("\n");
}


