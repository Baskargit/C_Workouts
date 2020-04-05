// 

#include<stdio.h>

int main()
{
    unsigned int n;
    scanf("%d",&n);

    unsigned int positiveArray[n],positiveArrayCounter = 0,firstMinPos = 0,flag = 1;
    for (unsigned int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d",&temp);

        if (flag && temp >= 0)
        {
            positiveArray[positiveArrayCounter++] = temp;
            firstMinPos = temp;
            flag = 0;
        }
        else
        {
            if (temp >= 0)
            {
                positiveArray[positiveArrayCounter++] = temp;
                firstMinPos = (temp < firstMinPos) ? temp : firstMinPos;
            }
        }
    }

    unsigned int smallPos = firstMinPos + 1;

    if (firstMinPos <= 1)
    {
        while (1)
        {
            flag = 1;

            for (unsigned int i = 0; i < positiveArrayCounter; i++)
            {
                if (positiveArray[i] == smallPos)
                {
                    flag = 0;
                    smallPos++;
                    break;
                }
            }

            if (flag)
            {
                break;
            }
        }
    }
    else
    {
        smallPos = 1;
    }
    
    
    printf("%d\n",smallPos);
    return 0;
}

/*

Input:
22
8 45 -21 -13 -15 43 -32 -22 -7 -39 -22 -21 26 -46 -7 13 -37 -12 -44 -10 -46 -32

Its Correct output is:
1

And Your Code's output is:
9

Input:
85
-47 1 4 49 -18 10 26 18 -11 -38 -24 36 44 -11 45 20 -16 28 17 -49 47 -48 -33 42 2 6 -49 30 36 -9 15 39 -6 -31 -10 -21 -19 -33 47 21 31 25 -41 -23 17 6 47 3 36 15 -44 33 -31 -26 -22 21 -18 -21 -47 -31 20 18 -42 -35 -10 -1 46 -27 -32 -5 -4 1 -29 5 29 38 14 -22 -9 0 43 -50 -16 14 -26

Its Correct output is:
7

And Your Code's output is:
-46

*/