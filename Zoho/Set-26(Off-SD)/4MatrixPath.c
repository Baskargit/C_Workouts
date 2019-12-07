/*
4. NxN matrix will be provided. 0->block, 1->Not a block
Always starting point is (0,0), Ending point is (N-1,N-1).
You have to go from starting point to ending point. One valid solution is enough.
Example:

 
   Input:
   N=4 
   1 1 0 0
   1 0 0 1
   1 1 1 1
   0 0 0 1

   Output:
   _ 1 0 0
   _ 0 0 1
   _ _ _ _
   0 0 0 _

*/

#include <stdio.h>
#include <stdbool.h>

bool proceedbottom(int m,int n,int currentrow,int currentcol,int matrix[][n]);

int main()
{
    int m = 4 , n = 4;

    int matrix[][4] = { {1,0,0,0},
                        {1,1,1,1},
                        {1,0,0,1},
                        {1,1,1,1}
                      };

    bool pathfound = false;
    int i=0,j=0;

    while (i < m)
    {
        if(matrix[i+1][j] == 1 && matrix[i][j+1] == 1) 
        {
            if(proceedbottom(m,n,i,j,matrix))
            {
                matrix[i][j] = 7;
                i++;
            } else {
                matrix[i][j] = 7;
                j++;
            }
        } 
        else if(matrix[i+1][j] == 1 && matrix[i][j+1] == 0) 
        {
            matrix[i][j] = 7;
            i++;
        } 
        else if(matrix[i+1][j] == 0 && matrix[i][j+1] == 1) 
        {
            matrix[i][j] = 7;
            j++;
        } 
        else {
            if(i == m  && j == n ) {
                pathfound = true;
                matrix[i][j] = 7;
            }
            break;
        }
    }
    
    /*

    for (; i < m; i++)
    {
        pathfound = false;

        for (; j < n; j++)
        {
            if(matrix[i][j] != 0) 
            {
                // Till before wall
                if(j != n - 1) 
                {
                    if(matrix[i+1][j] == 1) {
                        pathfound = true;
                        matrix[i][j] = 7;

                        if(proceedbottom(m,n,i,j,matrix)) {
                            
                        }
                        break;
                    }
                } else { // If end of the wall
                    if(matrix[i+1][j] == 1 && i != m - 1) {
                        pathfound = true;
                        matrix[i][j] = 7;
                        break;
                    } else if(matrix[i][j] == 1 && (i == m - 1 && j == n - 1)){
                        pathfound = true;
                        matrix[i][j] = 7;
                        break;
                    }
                }
                // Print path
                matrix[i][j] = 7;
            }
            break;
        }
        if(!pathfound) {
            break;
        }
    }

    */
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    
    printf("Pathfound : %d\n",pathfound);

    return 0;
}

bool proceedbottom(int totalrows,int totalcols,int currentrow,int currentcol,int matrix[][totalcols])
{
    int i = currentrow , j = currentcol;

    // row check till bottom left
    while (i < totalrows)
    {
        if(matrix[i][currentcol] == 0) {
            return false;
        }
        i++;
    }

    // col check till bottom right
    i--;
    while (j < totalcols)
    {
        if(matrix[i][j] == 0) {
            return false;
        }
        j++;
    }
    
    return true;
}