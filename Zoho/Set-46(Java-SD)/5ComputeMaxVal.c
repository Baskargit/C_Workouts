/*
Given an array of integers, compute the maximum value for each integer in the index, 
by either summing all the digits or multiplying all the digits. 
(Choose which operation gives the maximum value)

Input:
5
120 24 71 10 59
Output:
3 8 8 1 45

Explanation: 
For index 0, the integer is 120. Summing the digits will give 3, and whereas Multiplying the digits gives 0.
Thus, maximum of this two is 3.

*/

#include<stdio.h>

void computeMaxValue(int n,int array[n],int currentN,int maxValue[n]);
int getAddValue(int n);
int getMulValue(int n);
void printNewMaxValues(int n,int maxValue[n]);

int main()
{
    int n;
    int array[] = {1234,24,71,10,59};
    n = sizeof(array)/sizeof(int);

    int maxValue[n];
    computeMaxValue(n,array,0,maxValue);
    printNewMaxValues(n,maxValue);
    return 0;
}

void computeMaxValue(int n,int array[n],int currentN,int maxValue[n])
{
    if (currentN < n)
    {
        int addValue = getAddValue(array[currentN]);
        int mulValue = getMulValue(array[currentN]);

        maxValue[currentN] = (addValue > mulValue) ? addValue : mulValue;   
        return computeMaxValue(n,array,currentN + 1,maxValue);
    }
    else
    {
        return;
    }
}

int getAddValue(int n)
{
    return (n > 9) ? n % 10 + getAddValue(n/10) : n;
}

int getMulValue(int n)
{
    return (n > 9) ? n % 10 * getMulValue(n/10) : n;
}

void printNewMaxValues(int n,int maxValue[n])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",maxValue[i]);
    }
    printf("\n");
}