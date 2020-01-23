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
    int sourcei = -1,sourcej = -1;
    bool destinationExists = false,sourceExists = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&matrix[i][j]);
            traversedPaths[i][j] = (matrix[i][j] != WALL) ? TRAVERSE : 0;
            sourcei = (matrix[i][j] == SOURCE) ? i : sourcei;
            sourcej = (matrix[i][j] == SOURCE) ? j : sourcej;
            destinationExists = (matrix[i][j] == DESTINATION) ? true : destinationExists;
            sourceExists = (matrix[i][j] == SOURCE) ? true : sourceExists;
        }
    }

    if (sourceExists && destinationExists) // If there is a SOURCE and DESTINATION
    {
        printf("Pathexists : %s\n",pathexists(n,m,matrix,sourcei,sourcej,traversedPaths) ? "Yes" : "No");
    }
    else
    {
        printf("Missing \"SOURCE\" or \"DESTINATION\"\n");
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
3 0 2 0 3
3 0 0 0 3
3 3 3 3 3

21 16
3 0 0 0 0 0 0 0 0 2 0 0 0 0 0 0
3
3
3
3
3
3
3
3
3
3
3
3
3
3
3
3
3
3
3
3 3 3 1 3 3 3 3 3 3 3 3 3 3 3 3
*/