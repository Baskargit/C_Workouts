#include<stdio.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    int matrix[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d ",matrix[i][j]);
            }
        }
        else
        {
            for (int j = m-1; j >= 0; j--)
            {
                printf("%d ",matrix[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}

/*
4 5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20

*/
