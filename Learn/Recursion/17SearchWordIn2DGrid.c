/*
Search a Word in a 2D Grid of characters in all 8 directions

3 13
GEEKSFORGEEKS
GEEKSQUIZGEEK
IDEQAPRACTICE

!!!!!! Improper implementation !!!!!!!!!!!

*/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>

// bool wordExists(int n,int m,int currentN,int currentM,char grid[n][m],char searchFor[],int searchForlen,int searchForPtr,bool searchInProgress);
int wordExists(int n,int m,int currentN,int currentM,char grid[n][m],char searchFor[],int searchForlen,int searchForPtr,bool searchInProgress);


int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    char grid[n][m];
    char searchFor[] = "GEEKK";
    for (int i = 0; i < n; i++)
    {
        getchar();
        for (int j = 0; j < m; j++)
        {
            scanf("%c",&grid[i][j]);
        }
    }
    
    wordExists(n,m,0,0,grid,searchFor,strlen(searchFor),0,false);
    return 0;
}


int wordExists(int n,int m,int currentN,int currentM,char grid[n][m],char searchFor[],int searchForlen,int searchForPtr,bool searchInProgress)
{
    if (currentN >= 0 && currentN < n && currentM >=0 && currentM < m)
    {
        if (searchInProgress)
        {
            return (currentN-1 >=0 && grid[currentN-1][currentM] == searchFor[searchForPtr] && (grid[currentN-1][currentM] == searchFor[searchForPtr+1] || wordExists(n,m,currentN - 1,currentM,grid,searchFor,searchForlen,searchForPtr + 1,true) == searchForlen))
                ? searchForlen
                :(currentN-1 >=0 && currentM+1 < m && grid[currentN-1][currentM+1] == searchFor[searchForPtr] && (grid[currentN-1][currentM+1] == searchFor[searchForPtr+1] || wordExists(n,m,currentN-1,currentM+1,grid,searchFor,searchForlen,searchForPtr + 1,true) == searchForlen))
                ? searchForlen
                :(currentM+1 < m && grid[currentN][currentM+1] == searchFor[searchForPtr] && (grid[currentN][currentM+1] == searchFor[searchForPtr+1] || wordExists(n,m,currentN,currentM+1,grid,searchFor,searchForlen,searchForPtr + 1,true) == searchForlen))
                ?searchForlen
                :(currentN+1 < n && currentM+1 < m && grid[currentN+1][currentM+1] == searchFor[searchForPtr] && (grid[currentN+1][currentM+1] == searchFor[searchForPtr+1] || wordExists(n,m,currentN+1,currentM+1,grid,searchFor,searchForlen,searchForPtr + 1,true) == searchForlen))
                ?searchForlen
                :(currentN+1 < n && grid[currentN+1][currentM] == searchFor[searchForPtr] && (grid[currentN+1][currentM] == searchFor[searchForPtr+1] || wordExists(n,m,currentN+1,currentM,grid,searchFor,searchForlen,searchForPtr + 1,true) == searchForlen))
                ?searchForlen
                :(currentN+1 < n && currentM-1 >= 0 && grid[currentN+1][currentM-1] == searchFor[searchForPtr] && (grid[currentN+1][currentM-1] == searchFor[searchForPtr+1] || wordExists(n,m,currentN+1,currentM-1,grid,searchFor,searchForlen,searchForPtr + 1,true) == searchForlen))
                ?searchForlen
                :(currentM-1 >= 0 && grid[currentN][currentM-1] == searchFor[searchForPtr] && (grid[currentN][currentM-1] == searchFor[searchForPtr+1] || wordExists(n,m,currentN,currentM-1,grid,searchFor,searchForlen,searchForPtr + 1,true) == searchForlen))
                ?searchForlen
                :(currentN-1 >= 0 && currentM-1 >= 0 && grid[currentN-1][currentM-1] == searchFor[searchForPtr] && (grid[currentN-1][currentM-1] == searchFor[searchForPtr+1] || wordExists(n,m,currentN-1,currentM-1,grid,searchFor,searchForlen,searchForPtr + 1,true) == searchForlen))
                ?searchForlen
                :0;
        }
        else
        {
            for (; currentN < n; currentN++)
            {
                for (currentM = 0; currentM < m; currentM++)
                {
                    if (grid[currentN][currentM] == searchFor[0]) // If first letter matched
                    {
                        if (wordExists(n,m,currentN,currentM,grid,searchFor,searchForlen,1,true) == searchForlen)
                        {
                            printf("Match found at : %d,%d\n",currentN,currentM);
                        }
                    }
                }   
            }
        }
        
    }
    else
    {
        return 0;
    }
    
}


/*
bool wordExists(int n,int m,int currentN,int currentM,char grid[n][m],char searchFor[],int searchForlen,int searchForPtr,bool searchInProgress)
{
    if (currentN >= 0 && currentN < n && currentM >=0 && currentM < m)
    {
        if (searchInProgress)
        {
            if (searchForPtr == searchForlen) // Word matched
            {
                return true;
            }
            else
            {
                if (grid[currentN][currentM] == searchFor[searchForPtr]) // continue searching
                {
                    return wordExists(n,m,currentN - 1,currentM,grid,searchFor,searchForlen,searchForPtr + 1,true)
                            ? true
                            : wordExists(n,m,currentN-1,currentM+1,grid,searchFor,searchForlen,searchForPtr + 1,true)
                            ? true
                            : wordExists(n,m,currentN,currentM+1,grid,searchFor,searchForlen,searchForPtr + 1,true)
                            ? true
                            : wordExists(n,m,currentN+1,currentM+1,grid,searchFor,searchForlen,searchForPtr + 1,true)
                            ? true
                            : wordExists(n,m,currentN+1,currentM,grid,searchFor,searchForlen,searchForPtr + 1,true)
                            ? true
                            : wordExists(n,m,currentN+1,currentM-1,grid,searchFor,searchForlen,searchForPtr + 1,true)
                            ? true
                            : wordExists(n,m,currentN,currentM-1,grid,searchFor,searchForlen,searchForPtr + 1,true)
                            ? true
                            : wordExists(n,m,currentN-1,currentM-1,grid,searchFor,searchForlen,searchForPtr + 1,true);
                }
                else
                {
                    return false; // letter Not matched
                }
                
            }
        }
        else
        {
            bool wordExist = false;

            for (; currentN < n; currentN++)
            {
                for (currentM = 0; currentM < m; currentM++)
                {
                    if (grid[currentN][currentM] == searchFor[0]) // If first letter matched
                    {
                        if (wordExists(n,m,currentN,currentM,grid,searchFor,searchForlen,0,true))
                        {
                            wordExist = true;
                            printf("Match found at : %d,%d\n",currentN,currentM);
                        }
                    }
                }   
            }

            return wordExist;
        }
    }
    else
    {
        return false;
    }
}

/*

3 13
GEEKSFORGEEKS
GEEKSQUIZGEEK
IDEQAPRACTICE



*/