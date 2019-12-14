// 12:39
// https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately/0
// Access problem
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

    int front = 0,rear = n - 1;
    
    while (front < rear && rear > front)
    {
        printf("%d %d ",arr[front++],arr[rear--]);
    }

    if(front == rear) {
        printf("%d",arr[front]);
    }

    printf("\n");
    return 0;
}
