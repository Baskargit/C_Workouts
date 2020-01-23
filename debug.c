/*
Given a N X N matrix (M) filled with 1, 0, 2, 3. 
The task is to find whether there is a path possible from source to destination, 
while traversing through blank cells only. 

You can traverse up, down, right and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.

Note: there is only single source and single destination.
*/

#include<stdio.h>
#include<stdbool.h>

#define WALL 0
#define SOURCE 1
#define DESTINATION 2
#define PATH 3
#define TRAVERSE 1

bool pathexists(int n,int m,int matrix[n][m],int currentN,int currentM,int traversedPaths[n][m]);

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    
    int matrix[n][m];
    int traversedPaths[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&matrix[i][j]);
            traversedPaths[i][j] = (matrix[i][j] == PATH) ? TRAVERSE : 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == SOURCE)
            {
                printf("Pathexists : %d\n",pathexists(n,m,matrix,i,j,traversedPaths));
                i = n;
                break;
            }   
        }
    }
    return 0;
}

bool pathexists(int n,int m,int matrix[n][m],int currentN,int currentM,int traversedPaths[n][m])
{
    if (currentN >= 0 && currentN < n && currentM >=0 && currentM < m && traversedPaths[currentN][currentM] == TRAVERSE)
    {
        if (matrix[currentN][currentM] == DESTINATION)
        {
            return true; // Path found
        }
        else if (matrix[currentN][currentM] == WALL)
        {
            return false; // Wall 
        }
        else
        {
            traversedPaths[currentN][currentM] = 0;

            return (pathexists(n,m,matrix,currentN-1,currentM,traversedPaths))
                    ? true
                    : (pathexists(n,m,matrix,currentN,currentM+1,traversedPaths))
                    ? true
                    : (pathexists(n,m,matrix,currentN+1,currentM,traversedPaths))
                    ? true
                    : pathexists(n,m,matrix,currentN,currentM-1,traversedPaths);
        }
    }
    else
    {
        return false;
    }
}

/*
3 3
2 3 3
0 0 3
1 3 3

3 3
2 0 3
0 0 3
1 3 3

5 5
3 3 1 0 3
3 3 0 3 3
3 0 2 3 3
3 0 3 0 3
3 3 3 3 3

5 5
3 3 1 0 3
3 3 0 3 3
3 0 2 3 3
3 0 0 0 3
3 3 3 3 3
*/