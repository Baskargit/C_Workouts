// 8:52 - 8:59

#include <stdio.h>

int main()
{
    int n,threshold;
    scanf("%d%d",&n,&threshold);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += (arr[i] != 1)
                    ? (arr[i] % threshold == 0) ? arr[i]/threshold : arr[i]/threshold + 1
                    : arr[i];
    }

    printf("Count : %d\n",count);
    return 0;
}

/*
i/p {5,8,10,13,6,2};threshold = 3;
      o/p  count = 17

6 3
5 8 10 13 6 2

*/