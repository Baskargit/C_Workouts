/*
2 : 35
https://practice.geeksforgeeks.org/problems/next-happy-number/0
*/

// Not working

#include<stdio.h>
#include<stdbool.h>

unsigned long long int powof(int base,int power);
void findsquaresof(int n,int squaresof[n]);
void printsquaresof(int *squaresof);

int nextHappyNumber(int nextHappyNum,int squareSum,int buffercounter,int buffer[],int squaresof[]);
bool isleads1(int n);
bool sumNotRepeated(int sum,int buffercounter,int buffer[]);

int main()
{
    int n = 10;
    int squaresof[1000],buffer[1000];
    findsquaresof(0,squaresof);
    // printsquaresof(squaresof);
    
    printf("Next happy num : %d\n",nextHappyNumber(n+1,n+1,0,buffer,squaresof));
    return 0;
}

int nextHappyNumber(int nextHappyNum,int squareSum,int buffercounter,int buffer[],int squaresof[])
{
    printf("dfvd\n");

    // If loop detected proceed with next number
    if (!sumNotRepeated(squareSum,buffercounter,buffer))
    {
        nextHappyNumber(nextHappyNum+1,0,0,buffer,squaresof);
    }
    
    if (squareSum > 0 && squareSum < 10)
    {
        buffer[buffercounter] = squaresof[squareSum];
        squareSum = buffer[buffercounter];
    }
    else if (squareSum > 9 && squareSum < 100)
    {
        int digit1,digit2;

        digit2 = squareSum % 10;
        digit1 = (squareSum/10) % 10;
        buffer[buffercounter] = squaresof[digit1] + squaresof[digit2];
        squareSum = buffer[buffercounter];
    }
    else
    {
        int digit1,digit2,digit3;

        digit3 = squareSum % 10;
        digit2 = (squareSum/10) % 10;
        digit3 = (squareSum/100) % 10;
        buffer[buffercounter] = squaresof[digit1] + squaresof[digit2] + squaresof[digit3];
        squareSum = buffer[buffercounter];
    }

    // Base condition
    if (isleads1(squareSum))
    {
        return nextHappyNum;
    }
    
    return nextHappyNumber(nextHappyNum,buffer[buffercounter],buffercounter+1,buffer,squaresof);
}

bool isleads1(int nextHappyNum)
{
    int remainder = 0;

    while (nextHappyNum)
    {
        remainder = nextHappyNum % 10;
        nextHappyNum /= 10;
    }
    
    return (remainder == 1) ? true : false;
}

bool sumNotRepeated(int sum,int buffercounter,int buffer[])
{
    for (int i = 0; i < buffercounter; i++)
    {
        if (buffer[i] == sum)
        {
            return false;
        }
    }
    return true;
}

unsigned long long int powof(int base,int power)
{
    return (power) ? base * powof(base,power - 1) : 1;
}

void findsquaresof(int n,int squaresof[n])
{
    if (n < 1000)
    {
        squaresof[n] = powof(n,2);
        findsquaresof(n+1,squaresof);
    }
}

void printsquaresof(int *squaresof)
{
    for (int i = 0; i < 1000; i++)
    {
        printf("%d\n",squaresof[i]);
    }
    
}