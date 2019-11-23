#include <stdio.h>

void printArray(int *arr,int size);

void BubbleSort(int *arr,int size);


int main()
{
    int arr[5] = {3,5,1,4,2};

    printArray(arr,sizeof(arr)/sizeof(int));

    BubbleSort(arr,sizeof(arr)/sizeof(int));

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

void BubbleSort(int *arr,int size)
{
    // 1.Compare the adjacent value
    // 2.If adjacent value less than current position value -> Perform 'SWAP'.
    // 3.Ignore the Sorted the element on every iteration

    int min_index;

    for (int i = 0; i < size; i++)
    {    
        // 3. (j < size - i) => Ignores the Sorted the elements on every iteration    
        for (int j = 0; j < size - i; j++)
        {
            // 1.Compare the adjacent value
            if (*(arr+j) > *(arr+j+1))
            {
                // 2.Swap
                int temp =  *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            }
            
        }
    }
    
}


