/*
Assume there exists infinite grid, you’re given initial position x, y. 
Inputs will be movements either L or R or U or D. After n inputs, 
you need to give the current position.

Input: 
4 5 //initial position x, y
9 //number of movements
U L R R D D U L R //7 movements

Output:
5 5
*/

#include<stdio.h>

void printFinalPosition(int n,char movements[n],int currentN,int x,int y);

int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    int n;
    scanf("%d",&n);

    char movements[n];
    getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%c",&movements[i]);
    }
    
    printFinalPosition(n,movements,0,x,y);
    return 0;
}

void printFinalPosition(int n,char movements[n],int currentN,int x,int y)
{
    if (currentN < n)
    {
        switch (movements[currentN])
        {
            case 'U':
                return printFinalPosition(n,movements,currentN + 1,x - 1,y);
            case 'R':
                return printFinalPosition(n,movements,currentN + 1,x,y + 1);
            case 'D':
                return printFinalPosition(n,movements,currentN + 1,x + 1,y);
            case 'L':
                return printFinalPosition(n,movements,currentN + 1,x,y - 1);
            
            default:
                return printFinalPosition(n,movements,currentN + 1,x,y);
        }
    }
    else
    {
        printf("Final position : %d,%d\n",x,y);
        return;
    }
}

/*
Input: 
4 5
9
ULRRDDULR

Output:
5 5

*/