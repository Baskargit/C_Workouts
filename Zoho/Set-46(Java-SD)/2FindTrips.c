/*
Given an array of values persons[], each represents the weight of the persons.
There will be infinite bikes available.
Given a value K which represents the maximum weight that a bike accommodates.
Along with that one more condition, a bike can carry 2 persons at a time.
You need to find out the least number of times, the bike trips are made.

Input
5 // n
50 60 90 120 70 // n persons weights
110 // K => max weight a bike accommodates
2 // P => Max no of person a bike accommodates

Output


*/


#include<stdio.h>
#define DROPED 0
#define NOTDROPED 1

int findTrips(int n,int weights[n],int maxWeight,int maxPersons,int currentN,int currentPersonCount,int currentWeight,int dropped[n]);

int main()
{
    int n;
    scanf("%d",&n);
    int weights[n],dropped[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&weights[i]);
        dropped[i] = NOTDROPED;
    }

    int maxWeight;
    scanf("%d",&maxWeight);
    int maxPersons;
    scanf("%d",&maxPersons);

    printf("Mintrip : %d\n",findTrips(n,weights,maxWeight,maxPersons,0,0,0,dropped));
    return 0;
}


int findTrips(int n,int weights[n],int maxWeight,int maxPersons,int currentN,int currentPersonCount,int currentWeight,int dropped[n])
{
    if (currentN < n)
    {
        if (dropped[currentN]) // NOTDROPED
        {
            if (currentPersonCount == maxPersons && currentWeight <= maxWeight)
            {
                printf("Met\n");
                return 1 + findTrips(n,weights,maxWeight,maxPersons,currentN + 1,0,0,dropped);
            }  
            else if (currentPersonCount < maxPersons && currentWeight < maxWeight)
            {
                if (currentWeight + weights[currentN + 1] <= maxWeight)
                {
                    dropped[currentN + 1] = DROPED;
                    return findTrips(n,weights,maxWeight,maxPersons,currentN+1,currentPersonCount+1,currentWeight +weights[currentN+1],dropped);
                }
                else
                {
                    return findTrips(n,weights,maxWeight,maxPersons,currentN + 1,currentPersonCount,currentWeight,dropped);
                }                
            }
            else
            {
                return 0;
            }   
        }
        else
        {
            return findTrips(n,weights,maxWeight,maxPersons,currentN + 1,currentPersonCount,currentWeight,dropped);
        }
    }
    else
    {
        return 0;
    }
    
}

/*

Input
5
50 60 90 120 70
110
2
Output

*/