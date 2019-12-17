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
        // Get pathcount
        int pathcount = 0;

        for (int i = 0; i < 4; i++)
        {
            int currenti = sourcei + x[i];
            int currentj = sourcej + y[i];

            if(currenti >=0 && currenti < n && currentj >=0 && currentj < n)
            {
                if (grid[currenti][currentj] == 3 && traversedpaths[currenti][currentj] == 0) {
                    pathcount++;
                } else if(grid[currenti][currentj] == 2) {
                    // Destination found
                    ispathfound = true;
                    proceed = false;
                    break;
                } else {
                    // No path and destination
                    proceed = false;
                }
                
            }
        }

        if (proceed)
        {
            if (pathcount == 1)
            {
                for (int i = 0; i < 4; i++)
                {
                    int currenti = sourcei + x[i];
                    int currentj = sourcej + y[i];

                    if(currenti >=0 && currenti < n && currentj >=0 && currentj < n)
                    {
                        if (grid[currenti][currentj] == 3 && traversedpaths[currenti][currentj] == 0) 
                        {
                            traversedpaths[sourcei][sourcej] = 1;
                        } else if(grid[currenti][currentj] == 2) {
                            // Destination found
                            ispathfound = true;
                            proceed = false;
                            break;
                        } else {
                            // No path and destination
                            proceed = false;
                        }
                        
                    }
                }
            }
            else
            {
                for (int z = 0; z < pathcount; z++)
                {
                    bool proceednextpath = true;

                    for (int i = 0; i < 4; i++)
                    {
                        int currenti = sourcei + x[i];
                        int currentj = sourcej + y[i];

                        if(currenti >=0 && currenti < n && currentj >=0 && currentj < n)
                        {
                            if (grid[currenti][currentj] == 3 && traversedpaths[currenti][currentj] == 0) 
                            {
                                int tempi = currenti;
                                int tempj = currentj;
                                while (proceednextpath)
                                {
                                    for (int j = 0; j < 4; j++)
                                    {
                                        if (((tempi + x[j] >=0 && tempi + x[j] < n) && (tempj + y[j] >=0 && tempj + y[j] < n)))
                                        {
                                            if (grid[tempi + x[j]][tempj + y[j]] == 3)
                                            {
                                                ispathfound = true;
                                                break;
                                            }
                                            else
                                            {
                                                proceednextpath = false;
                                            }
                                            
                                        }
                                        
                                    }
                                    
                                }
                            }
                        }
                    }

                    
                    
                }
                
            }
            
            
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
