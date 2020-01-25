/*
Search a Word in a 2D Grid of characters in all 8 directions (Non-Zig Zag)

https://www.geeksforgeeks.org/search-a-word-in-a-2d-grid-of-characters/

3 13
GEEKSFORGEEKS
GEEKSQUIZGEEK
IDEQAPRACTICE

13 13
THSMALLTRPTLA
EAPCRSRPSPBLS
ELICFTOSPARQH
NIHDETSERIUVC
NBCDWUSJJIYBD
YMAESYCENOTNY
PIETGNLNGTDSJ
PSCUDUEGCAAGG
OTGGCBWUWJEJS
IQLEAVQKQNTTD
NDLSDCAHTMRER
TOCTGHJHDSETY
MGMIJRTYYUIOP

*/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool wordExists(int n,int m,int currentN,int currentM,char grid[n][m],char searchFor[],bool searchInProgress);
bool verifyWord(int n,int m,int x,int y,int currentN,int currentM,char grid[n][m],char searchFor[],int pos);

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    char grid[n][m];
    char searchFor[] = "GEEK";
    for (int i = 0; i < n; i++)
    {
        getchar();
        for (int j = 0; j < m; j++)
        {
            scanf("%c",&grid[i][j]);
        }
    }
    
    wordExists(n,m,0,0,grid,searchFor,false);
    return 0;
}

bool wordExists(int n,int m,int currentN,int currentM,char grid[n][m],char searchFor[],bool searchInProgress)
{
    if (searchInProgress)
    {
        if (searchFor[1] == '\0')
        {
            return true;
        }
        else
        {
            return 
                verifyWord(n,m,-1,0,currentN,currentM,grid,searchFor,1) || 
                verifyWord(n,m,-1,1,currentN,currentM,grid,searchFor,1) || 
                verifyWord(n,m,0,1,currentN,currentM,grid,searchFor,1) || 
                verifyWord(n,m,1,1,currentN,currentM,grid,searchFor,1) ||
                verifyWord(n,m,1,0,currentN,currentM,grid,searchFor,1) || 
                verifyWord(n,m,1,-1,currentN,currentM,grid,searchFor,1) || 
                verifyWord(n,m,0,-1,currentN,currentM,grid,searchFor,1) || 
                verifyWord(n,m,-1,-1,currentN,currentM,grid,searchFor,1);
        }
        
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == searchFor[0])
                {
                    if (wordExists(n,m,i,j,grid,searchFor,true))
                    {
                        printf("Match found at : %d,%d\n",i,j);
                    }
                }
            }
        }
    }
}

bool verifyWord(int n,int m,int x,int y,int currentN,int currentM,char grid[n][m],char searchFor[],int pos)
{
    // int x,int y params points the x and y co-ordinates in the cartesian plane (or) graph plot

    int X = currentN+x;
    int Y = currentM+y;
    
    if (X >= 0 && X < n && Y >=0 && Y < m)
    {
        if (grid[X][Y] == searchFor[pos])
        {
            return (searchFor[pos+1] == '\0') ? true : verifyWord(n,m,x,y,X,Y,grid,searchFor,pos+1);
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}