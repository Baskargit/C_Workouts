/*
Link : https://www.geeksforgeeks.org/zoho-interview-experience-off-campus-for-java-software-developer/

Assume there exists infinite grid, you’re given initial position x, y. 
Inputs will be movements either L or R or U or D. After n inputs, you need to give the current position.

Input: 
4 5 //initial position x, y
9 //number of movements
U L R R D D U L R //7 movements

Output:
5 5

*/

#include<stdio.h>

void findFinalPos(int n,int *x,int *y,int initialx,int initialy,char movements[n]);

int main()
{
    int x = 4, y = 5;
    int finalx = x,finaly = y;
    char movements[] = "U L R R D D U L R";
    
    findFinalPos(0,&finalx,&finaly,x,y,movements);
    printf("%d,%d\n",finalx,finaly);
    return 0;
}

void findFinalPos(int n,int *x,int *y,int initialx,int initialy,char movements[n])
{
    if (movements[n])
    {
        switch (movements[n])
        {
            case 'U':
                --initialx;
                *x = initialx;
                break;

            case 'R' :
                ++initialy;
                *y = initialy;
                break;

            case 'D' :
                ++initialx;
                *x = initialx;
                break;

            case 'L':
                --initialy;
                *y = initialy;
                break;
            
            default:
                break;
        }

        return findFinalPos(++n,x,y,initialx,initialy,movements);
    }
    
    return;
}
