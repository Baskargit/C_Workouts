/*
Q.no.1
Given N. print the following snake pattern.
condition: must not use arrays ( 1D array  or 2D array like Matrix ).

(say N = 3)
1 2 3
6 5 4
7 8 9

(say N = 4)
1 2 3  4
8 7 6  5
9 10 11 12
16 15 14 13


*/

#include<stdio.h>
#include<stdbool.h>

void snakepattern(int n,int tempN,int currentN,bool isforward);

int main()
{
    int n = 10;
    snakepattern(n,1,1,true);
    return 0;
}

void snakepattern(int n,int tempN,int currentN,bool isforward)
{
    if (isforward)
    {
        printf("%d ",currentN);

        if (currentN == tempN*n)
        {
            if (tempN == n && currentN == n*n)
            {
                printf("\n");
                return;
            }
            else
            {
                printf("\n");
                snakepattern(n,tempN+1,currentN+n,false);
            }
            
        }
        else
        {
            snakepattern(n,tempN,currentN+1,true);
        }
        
    }
    else
    {
        printf("%d ",currentN);

        if (tempN == n && currentN == tempN*n - n + 1)
        {
            printf("\n");
            return;
        }
        else if (currentN - 1 == (tempN - 1) * n)
        {
            printf("\n");
            snakepattern(n,tempN+1,currentN+n,true);
        }
        else
        {
            snakepattern(n,tempN,currentN-1,false);
        }
        
    }
    
}
