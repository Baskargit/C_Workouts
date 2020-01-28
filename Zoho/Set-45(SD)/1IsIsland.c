/*
1. -1 represents ocean and 1 represents land find the number of islands in the given matrix.

Input:   n*n matrix

1 -1 -1  1
-1  1 -1  1
-1 -1  1 -1
-1 -1 -1  1
Output: 
(two islands that I have bold in matrix at 1, 1 and 2, 2)

*/

#include<stdio.h>

void printIslands(int n,int m,int matrix[n][m],int currentN,int currentM);

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    int matrix[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    
    printIslands(n,m,matrix,0,0);
    return 0;
}

void printIslands(int n,int m,int matrix[n][m],int currentN,int currentM)
{
    if (currentN < n)
    {
        if (matrix[currentN][currentM] == 1)
        {
            if (currentN - 1 >=0 && currentN + 1 < n && currentM - 1 >= 0 && currentM + 1 < m)
            {
                if (matrix[currentN - 1][currentM] == -1 && matrix[currentN][currentM+1] == -1 && matrix[currentN+1][currentM] == -1 && matrix[currentN][currentM - 1] == -1)
                {
                    printf("Island --> %d,%d\n",currentN,currentM);
                }
            }
        }

        if (currentM + 1 < m)
        {
            return printIslands(n,m,matrix,currentN,currentM + 1);
        }
        else
        {
            return printIslands(n,m,matrix,currentN + 1,0);
        }
    }
    else
    {
        return;
    }
}

/*

4 4
1 -1 -1  1
-1  1 -1  1
-1 -1  1 -1
-1 -1 -1  1

*/
