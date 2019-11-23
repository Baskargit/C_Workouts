#include <stdio.h>

void printArray(int *arr,int size);

void Partition(int *arr,int size,int key);
void PartitionAdvanced(int *arr,int low,int high);

int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};

    printArray(arr,sizeof(arr)/sizeof(int));

    // Partition(arr,sizeof(arr)/sizeof(int),90);

    PartitionAdvanced(arr,0,sizeof(arr)/sizeof(int) - 1);

    printArray(arr,sizeof(arr)/sizeof(int));

    return 0;
}

void PartitionAdvanced(int *arr,int low,int high)
{
    int pivot = arr[low];

    int left = low + 1,right = high;

    for (; (right > left) ;)
    {
        for(;arr[left] < pivot;left++);
        for(;arr[right] > pivot;right++);

        if (right <= left)
        {
            arr[right] = pivot;
            break;
        }

        if (left < high && right > low)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp; 
        }
        
    }
    

}

void Partition(int *arr,int size,int key)
{
    printf("\n");

    int pivot = key;

    int partitionedArray[size];

    int i=0,j=size - 1,pos = 0;

    while (pos != size)
    {
        if (arr[pos] != pivot && arr[pos] <= pivot)
        {
            partitionedArray[i++] =  arr[pos];
        } else if(arr[pos] != pivot && arr[pos] >= pivot)
        {
            partitionedArray[j--] = arr[pos];
        }

        pos++;
    }

    partitionedArray[j] = pivot;

    printArray(partitionedArray,size);
    
}

void printArray(int *arr,int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
}