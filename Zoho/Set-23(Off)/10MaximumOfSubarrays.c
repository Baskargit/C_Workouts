#include <stdio.h>

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int i=0,j=0;

    while (i < n && j < n)
    {
        int subarrmax = arr[i];
        j = i + 1;

        while (j < i+k)
        {
            subarrmax = (arr[j] > subarrmax) ? arr[j] : subarrmax;
            j++;
        }

        i++;
        printf("%d ",subarrmax);
    }
    
    printf("\n");
    
    return 0;
}

/*

9 3
1 2 3 1 4 5 2 3 6

10 4
8 5 10 7 9 4 15 12 90 13

*/