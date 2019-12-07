#include <stdio.h>

void printMat(int row,int col,int M[row][col]);

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);

    int arr[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    printMat(m,n,arr);
    
    return 0;
}

void printMat(int row,int col,int M[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(M[i][j] == -1) 
            {
                break;    
            } 
            else 
            {
                j = 0;
                int isDuplicate = 1;
                for (int k = i+1; k < row; k++)
                {
                    if(M[k][0] != -1) 
                    {
                        j = 0;
                        isDuplicate = 1;
                        for (int l = 0; l < col; l++)
                        {
                            if(M[i][j++] != M[k][l]) {
                                isDuplicate = 0;
                                break;
                            }
                        }
                    }

                    if(isDuplicate) {
                        M[k][0] = -1;
                    }
                }
                j = col;
            }
        }

        if(M[i][0] != -1) 
        {
            for (int k = 0; k < col; k++)
            {
                printf("%d ",M[i][k]);
            }
            // printf("$");
        } 
        else {
            printf("$ ");
        }

        printf("\n");
    }
    
    printf("\n");
}

/*
Input
3 4
1 1 0 1 1 0 0 1 1 1 0 1

4 7
1 1 1 1 0 0 1 1 0 1 0 1 1 0 0 0 0 0 1 0 1 1 0 0 0 1 1 1 
10 3
0 0 1 1 1 0 1 0 1 1 1 1 0 1 0 0 1 0 1 0 1 0 0 1 0 0 0 1 1 1

Output
1 1 0 1 $1 0 0 1 $
*/
