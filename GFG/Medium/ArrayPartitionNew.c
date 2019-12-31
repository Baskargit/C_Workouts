#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n],totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
        totalsum += arr[i];
    }

    return 0;
}
