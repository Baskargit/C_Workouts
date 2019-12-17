// 4:05
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

void setTraversedPaths(int n,int traversedpaths[n][n]);

int main()
{
    int n;
    scanf("%d",&n);

    int grid[n][n];
    int sourcei = 0,sourcej = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&grid[i][j]);

            // Find source
            if(grid[i][j] == 1)
            {
                sourcei = i;
                sourcej = j;
            }
        }
    }
    printf("Source in %d,%d\n",sourcei,sourcej);
    printf("Grid \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d",grid[i][j]);
        }
        printf("\n");
    }
    
    bool isAlternatepathAvailable = false; 
    bool ispathfound = false;
    bool proceed = true;
    
    int x[] = {-1,0,1,0};
    int y[] = {0,1,0,-1};
    int traversedpaths[n][n];
    int backtrackpos[n][1];
    int altpathi,altpathj,altpathcount = 0;
    setTraversedPaths(n,traversedpaths);

   
    

    printf("traversedpath \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d",traversedpaths[i][j]);
        }
        printf("\n");
    }

    printf("%s\n",(ispathfound) ? "1" : "0");
    return 0;
}

void setTraversedPaths(int n,int traversedpaths[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            traversedpaths[i][j] = 0;
        }
    }
}

