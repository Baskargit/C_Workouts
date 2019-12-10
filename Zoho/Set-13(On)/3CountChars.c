/*
You’re given a number n. If write all the numbers from 1 to n in a paper,
we have to find the number of characters written on the paper.For example if n=13, 
the output should be 17 if n = 101, the output should be 195
*/

#include <stdio.h>

int main()
{
    int n = 999;

    int i = 1;
    int digitscount = 0;
    int currentmax = 9,currentmaxlength = 1;
    while (i <= n)
    {
        if(i <= currentmax) 
        {
            digitscount += currentmaxlength;
        }
        else
        {
            currentmax = (currentmax * 10) + 9;
            currentmaxlength++;
            digitscount +=  currentmaxlength;
        }

        i++;
    }
    
    printf("%d\n",digitscount);
    return 0;
}
