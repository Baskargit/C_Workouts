// 8:24

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
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[j] > arr[i]) 
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    // Print alternatively
    int front = 0,last = n - 1;
    while (front != last && front < last)
    {
        printf("%d %d ",arr[front++],arr[last--]);
    }
    
    if(front == last) {
        printf("%d",arr[front]);
    }
    
    printf("\n");
    return 0;
}

/*
7
5 2 8 7 4 3 9

6
5 2 8 7 4 3

*/
