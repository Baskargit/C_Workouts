// Accepted soln
// 0.01S

#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }

    int stack[n],stackpos = -1;
    int rowi,rowj = 0,rowcount = 0;
    for (int i = 0; i < n + (n - 1); i++)
    {
        rowi = (i >= n) ? n - 1 : i;
        rowcount = (i >= n) ? rowcount + 1 : 0;
        rowj = (i >= n) ? rowcount : 0;

        stack[++stackpos] = matrix[rowi][rowj];

        while(1)
        {
            if (rowi - 1 >= 0 && rowj + 1 < n)
            {
                rowi = rowi - 1;
                rowj = rowj + 1;
                // Push
                stack[++stackpos] = matrix[rowi][rowj];
            } else {
                break;
            }
        }

        // Pop
        while (stackpos >= 0)
        {
            printf("%d ",stack[stackpos--]);
        }

        printf("\n");
        stackpos = -1;
    }

    return 0;
}

/*
3
1 2 3
4 5 6
7 8 9

*/
