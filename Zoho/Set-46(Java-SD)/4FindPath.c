/*
Given a matrix MxN, 
you are initially in the 0, 0 position. The matrix is filled with ones and zeros. 
Value “one” represents the path is available, while “zero” represents the wall. 
You need to find the can you able to reach the (N-1)x(M-1) index in the matrix. 
You can move only along the "right" and "down" directions if there’s “one” available.
*/

#include<stdio.h>
#include<stdbool.h>
#define PATH 1
#define WALL 0

bool pathExists(int n,int m,int matrix[n][m],int currentN,int currentM);

static int callcount = 0;

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

    printf("Path exists : %s\n",(pathExists(n,m,matrix,0,0)) ? "Yes" : "No");
    printf("Total calls made : %d\n",callcount);
    return 0;
}

bool pathExists(int n,int m,int matrix[n][m],int currentN,int currentM)
{
    callcount++;

    if (currentN == 0 && currentM == 0 && matrix[currentN][currentM]) // SOURCE
    {
        return pathExists(n,m,matrix,currentN,currentM + 1) || pathExists(n,m,matrix,currentN + 1,currentM);
    }
    else
    {
        if (currentN < n)
        {
            if (currentM < m)
            {
                if (matrix[currentN][currentM] == PATH)
                {
                    if (currentN == n - 1 && currentM == m - 1) // DESTINATION
                    {
                        return true;
                    }
                    return pathExists(n,m,matrix,currentN,currentM + 1) || pathExists(n,m,matrix,currentN + 1,currentM);
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return pathExists(n,m,matrix,currentN + 1,0);
            }
        }
        else
        {
            return false;
        }
    }
    
}

bool pathExists1(int n,int m,int matrix[n][m],int currentN,int currentM)
{
    callcount++;

    if (currentN < n)
    {
        if (currentM < m)
        {
            if (matrix[currentN][currentM] == PATH)
            {
                if (currentN == n - 1 && currentM == m - 1) // bottom right
                {
                    return true;
                }
                return pathExists(n,m,matrix,currentN,currentM + 1) || pathExists(n,m,matrix,currentN + 1,currentM);
            }
            else
            {
                return false;
            }
        }
        else
        {
            return (currentM + 1 < m) ? pathExists(n,m,matrix,currentN,currentM + 1) : pathExists(n,m,matrix,currentN + 1,0);
        }
    }
    else
    {
        return false;
    }
}

/*

Input:
5 5
1 0 1 0 0
1 1 1 1 1
0 0 0 1 0
1 0 1 1 1
0 1 1 0 1
Output:
Yes

Input:
5 5
1 0 1 0 0
1 1 1 1 1
0 0 0 1 0
1 0 1 1 0
0 1 1 0 1
Output:
No

Input:
5 5
1 1 1 1 0
1 0 0 0 1
1 1 1 1 0
1 0 1 1 0
0 1 1 1 1
Output:
YES

Input:
5 5
1 1 1 1 0
1 0 0 0 1
1 0 1 1 0
1 0 1 1 0
0 1 1 1 1
Output:
NO

Input:
5 5
0 1 1 1 0
1 0 0 0 1
1 0 1 1 0
1 0 1 1 0
0 1 1 1 1
Output:
NO

*/