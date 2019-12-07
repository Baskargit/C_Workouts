/*
Input:
1
5
1 2 3 4 5

Output:
2 1 4 3 5
*/

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

    int n1 = (n % 2 == 0) ? n : n - 1;
    for (int i = 0; i < n1;)
    {
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        i = i+2;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
    return 0;
}
