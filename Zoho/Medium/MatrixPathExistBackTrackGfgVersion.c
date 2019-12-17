// Accepted answer
// 0.01 execution time
// Non-recursive version

#include<stdio.h>
#include<stdbool.h>
#define TRAVERSEDCONS 9

void initializeTraversedPaths(int n,int traversedpaths[n][n]);
int getPathcount(int n,int grid[n][n],int traversedpaths[n][n],int currenti,int currentj,int directioncount,int x[],int y[]);

int main()
{
	int testCaseCount;
    scanf("%d",&testCaseCount);
    
    for(int count=0; count<testCaseCount; count++)
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
        
        bool isAlternatepathAvailable = false; 
        bool ispathfound = false;
        bool proceed = true;
        
        int x[] = {-1,0,1,0};
        int y[] = {0,1,0,-1};
        int directioncount = 4;
        int traversedpaths[n][n];
        int backtracks[n*n][2],backtrackcount = 0,tempBTC = 0;
        int currenti = sourcei,currentj = sourcej;

        initializeTraversedPaths(n,traversedpaths);

        while (proceed && !ispathfound)
        {
            // Get pathcount
            int pathcount = getPathcount(n,grid,traversedpaths,currenti,currentj,directioncount,x,y);
            
            if (pathcount == 1) // If only one path
            {
                for (int i = 0; i < directioncount; i++)
                {
                    int tempi = currenti+x[i];
                    int tempj = currentj+y[i];

                    if(tempi >= 0 && tempi < n && tempj >= 0 && tempj < n && traversedpaths[tempi][tempj] != TRAVERSEDCONS)
                    {
                        if (grid[tempi][tempj] == 3)
                        {
                            // Set the current path as traversed
                            traversedpaths[currenti][currentj] = TRAVERSEDCONS;
                            currenti = tempi;
                            currentj = tempj;
                            break;
                        }
                        else if (grid[tempi][tempj] == 2)
                        {
                            ispathfound = true;
                            break;
                        }
                        
                    }
                }
            }
            else if (pathcount > 1) // If multiple paths available
            {
                isAlternatepathAvailable = true;
                backtracks[backtrackcount][0] = currenti;
                backtracks[backtrackcount][1] = currentj;
                backtrackcount++;
                tempBTC = backtrackcount;

                for (int i = 0; i < directioncount; i++)
                {
                    int tempi = currenti+x[i];
                    int tempj = currentj+y[i];

                    if(tempi >= 0 && tempi < n && tempj >= 0 && tempj < n) {
                        if (grid[tempi][tempj] == 3 && traversedpaths[tempi][tempj] != TRAVERSEDCONS) {
                            traversedpaths[currenti][currentj] = TRAVERSEDCONS;
                            currenti = tempi;
                            currentj = tempj;
                            break;
                        }
                    }
                }
            }
            else // If no path available
            {
                if (isAlternatepathAvailable && backtrackcount > 0)
                {
                    int pathcount1 = getPathcount(n,grid,traversedpaths,currenti,currentj,directioncount,x,y);

                    if(pathcount1 == 0) {
                        traversedpaths[currenti][currentj] = TRAVERSEDCONS;
                        backtrackcount--;

                        currenti = backtracks[backtrackcount][0];
                        currentj = backtracks[backtrackcount][1];
                    }
                }
                else
                {
                    proceed = 0;
                }
                
            }
        }
        
        printf("%d\n",ispathfound);
    }
    
	return 0;
}


int getPathcount(int n,int grid[n][n],int traversedpaths[n][n],int currenti,int currentj,int directioncount,int x[],int y[])
{
    int pathcount = 0;

    for (int i = 0; i < directioncount; i++)
    {
        int tempi = currenti+x[i];
        int tempj = currentj+y[i];

        pathcount = (tempi >= 0 && tempi < n && tempj >= 0 && tempj < n && traversedpaths[tempi][tempj] != TRAVERSEDCONS)
                        ? (grid[tempi][tempj] == 3 || grid[tempi][tempj] == 2)
                            ? pathcount + 1 
                            : pathcount
                        : pathcount;
    }
    
    return pathcount;
}

void initializeTraversedPaths(int n,int traversedpaths[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            traversedpaths[i][j] = 0;
        }
    }
}


