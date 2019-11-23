#include <stdio.h>

void printArray(int *arr,int size);

void BubbleSort(int *arr,int size);
void SelectionSort(int *arr,int size);

int main()
{
    int arr[5] = {3,5,1,4,2};

    printArray(arr,sizeof(arr)/sizeof(int));

    SelectionSort(arr,sizeof(arr)/sizeof(int));

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

void SelectionSort(int *arr,int size)
{
    // 1.Select the minimum value
    // 2.Swap
    // 3.Shift

    int min_index;

    for (int i = 0; i < size;)
    {
        min_index = i;
        
        for (int j = i+1; j < size; j++)
        {
            if (*(arr+j) < *(arr+min_index))
            {
                // 1.Select the minimum value
                min_index = j;
                printf("Minimum value = %d\n",*(arr+j));
            }
            
        }

        // 2.Swap the contents of min_index with current 'UNSORTED' index and vice versa
        int temp = *(arr+i);
        *(arr+i) = *(arr+min_index);
        *(arr+min_index) = temp;

        // 3.Shift
        i++;
        
    }
    
}


