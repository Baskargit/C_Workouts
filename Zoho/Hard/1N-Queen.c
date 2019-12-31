/*
// 5:53
https://practice.geeksforgeeks.org/problems/n-queen-problem/0

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack 
each other. Given an integer n, print all distinct solutions to the n-queens puzzle. 
Each solution contains distinct board configurations of the n-queens’ placement, 
where the solutions are a permutation of [1,2,3..n] in increasing order, 
here the number in the ith place denotes that the ith-column queen is placed in the row with that number. 

Input
2
1
4
Output:
[1 ]
[2 4 1 3 ] [3 1 4 2 ]

*/

// Wrong logic => Only pass n = 1,2,3,4
// No BackTracking Used

#include<stdio.h>
#define ATTACKSPOTCONS 1

void initializeAttackSpots(int n,int attackspots[n][n]);
void setAttactSpots(int n,int currenti,int currentj,int attackspots[n][n]);
int getQueenCount(int n,int attackspots[n][n]);
int storePossibilities(int n,int attackspots[n][n],int possibilecount,int possibilities[n][n]);

void printAttackSpots(int n,int attackspots[n][n]);

int main()
{
    int n = 7;

    int possibilities[n][n],possibilecount = 0;

    int attackspots[n][n];
    
    for (int i = 0; i < n; i++)
    {
        initializeAttackSpots(n,attackspots);
        setAttactSpots(n,0,i,attackspots);

        for (int j = 1; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                // Implement BackTrack here
                if (attackspots[j][k] == 0)
                {
                    setAttactSpots(n,j,k,attackspots);
                }
            }
        }
        
        if (getQueenCount(n,attackspots) == n)
        {
            storePossibilities(n,attackspots,possibilecount,possibilities);
            possibilecount++;
        }

        printAttackSpots(n,attackspots);
        printf("\n");
    }

    if (possibilecount)
    {
        for (int i = 0; i < possibilecount; i++)
        {
            printf("[");
            for (int j = 0; j < n; j++)
            {
                printf("%d ",possibilities[i][j]);
            }
            printf("] ");
        }
        
    } else {
        printf("-1");
    }
    
    printf("\n");
    printf("Possibilecount : %d\n",possibilecount);
    return 0;
}

int getQueenCount(int n,int attackspots[n][n])
{
    int queencount = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            queencount = (attackspots[i][j] == 0) ? queencount + 1 : queencount;        
        }
    }

    return queencount;
}

void setAttactSpots(int n,int currenti,int currentj,int attackspots[n][n])
{
    // -1,0 => 0,1 => 1,0 => 0,-1 (hor,ver)
    // -1,1 => 1,1 => 1,-1 => -1,-1 (diagonal)
    // Total 8 directions
    int x[] = {-1,0,1,0  ,-1,1,1,-1};
    int y[] = {0,1,0,-1  ,1,1,-1,-1};

    for (int i = 0; i < 8; i++)
    {
        int tempi = currenti + x[i];
        int tempj = currentj + y[i];

        if (tempi >= 0 && tempi < n && tempj >= 0 && tempj < n)
        {
            attackspots[tempi][tempj] = ATTACKSPOTCONS;

            while (((tempi = tempi + x[i]) >= 0 && tempi < n) && ((tempj = tempj + y[i]) >= 0 && tempj < n))
            {
                attackspots[tempi][tempj] = ATTACKSPOTCONS;
            }
            
        }  
    }
}

int storePossibilities(int n,int attackspots[n][n],int possibilecount,int possibilities[n][n])
{
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (attackspots[i][j] == 0)
            {
                possibilities[possibilecount][counter++] = j + 1;
            }                
        }
    }
}

void initializeAttackSpots(int n,int attackspots[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            attackspots[i][j] = 0;
        }
    }
}

void printAttackSpots(int n,int attackspots[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",attackspots[i][j]);
        }
        printf("\n");
    }
}


// initializeAttackSpots(n,attackspots);

// for (int i = 0; i < n; i++)
// {
//     initializeAttackSpots(n,attackspots);
//     setAttactSpots(n,i,0,attackspots);
//     printAttackSpots(n,attackspots);
//     printf("\n");
// }

// initializeAttackSpots(n,attackspots);
// setAttactSpots(n,0,1,attackspots);
// setAttactSpots(n,1,3,attackspots);
// setAttactSpots(n,2,0,attackspots);
// setAttactSpots(n,3,2,attackspots);
// printAttackSpots(n,attackspots);