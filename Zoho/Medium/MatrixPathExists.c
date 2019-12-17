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
    int altpathi,altpathj,altpathcount = 0;
    setTraversedPaths(n,traversedpaths);

    while (proceed)
    {
        // Check whether destination is nearby (or) not
        for (int i = 0; i < 4; i++)
        {
            int currenti = sourcei + x[i];
            int currentj = sourcej + y[i];
            
            // If nearby
            if((currenti >=0 && currenti < n) && (currentj >=0 && currentj < n) && grid[currenti][currentj] == 2) 
            {
                ispathfound = true;
                proceed = false;
                break;
            }
        }

        // If not nearby check blank wall available to move (or) not 
        if (proceed)
        {
            // Get paths Count
            int pathcount = 0;
            for (int i = 0; i < 4; i++)
            {
                int currenti = sourcei + x[i];
                int currentj = sourcej + y[i];

                pathcount = (((currenti >=0 && currenti < n) && (currentj >=0 && currentj < n)) 
                                && grid[currenti][currentj] == 3 && traversedpaths[currenti][currentj] == 0) 
                                ? pathcount + 1 : pathcount;
            }

            if (pathcount == 1) // Only Onepath available
            {
                for (int i = 0; i < 4; i++)
                {
                    int currenti = sourcei + x[i];
                    int currentj = sourcej + y[i];

                    if(((currenti >=0 && currenti < n) && (currentj >=0 && currentj < n)) && grid[currenti][currentj] == 3 && traversedpaths[currenti][currentj] == 0)
                    {
                        // Set previous path as traversed
                        traversedpaths[sourcei][sourcej] = 1;

                        // Set next open path
                        sourcei = currenti;
                        sourcej = currentj;
                        break;
                    }
                }
            }
            else if(pathcount > 1) //More than one path available from the current position
            {
                altpathi = sourcei;
                altpathj = sourcej;

                for (int i = 0; i < 4; i++)
                {
                    int currenti = sourcei + x[i];
                    int currentj = sourcej + y[i];

                    // Do not set the current path as a traversed
                    if(((currenti >=0 && currenti < n) && (currentj >=0 && currentj < n)) && grid[currenti][currentj] == 3 && traversedpaths[currenti][currentj] == 0)
                    {
                        traversedpaths[currenti][currentj] = 1;
                        // Set next open path
                        sourcei = currenti;
                        sourcej = currentj;
                        break;
                    } else {
                        // Don't set flags because another path need to be checked
                    }
                    
                }
            }
            else // No Path available
            {
                // Check whether alternate path exists (or) not
                if (isAlternatepathAvailable)
                {
                    // Set source to altpath
                    sourcei = altpathi;
                    sourcej = altpathj;

                    for (int i = 0; i < 4; i++)
                    {
                        int currenti = sourcei + x[i];
                        int currentj = sourcej + y[i];

                        if(((currenti >=0 && currenti < n) && (currentj >=0 && currentj < n)) && grid[currenti][currentj] == 3 && traversedpaths[currenti][currentj] == 0)
                        {
                            // traversedpaths[currenti][currentj] = 1;
                            // Set next open path
                            sourcei = currenti;
                            sourcej = currentj;
                            break;
                        } else {
                            isAlternatepathAvailable = ispathfound = proceed = false;
                        }
                        
                    }
                    printf("altpath \n");
                } else {
                    ispathfound = proceed =false;
                }
                
            }
            
        }
        else
        {
            // No need to proceed
            break;
        }
    }

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

/*
Test cases

Example:
Input:
2
4
3 0 0 0 0 3 3 0 0 1 0 3 0 2 3 3 
3
0 3 2 3 0 0 1 0 0

Output:
1
0

Input
4
0 0 3 3
2 3 3 3
0 3 3 3
1 3 3 3

4
0 0 3 3
2 0 3 3
0 3 3 3
1 3 3 3

4
2 0 3 3
0 3 3 3
0 3 3 3
1 0 3 3

4
2 3 3 3
0 0 3 3
0 0 3 3
1 3 3 3

*/
