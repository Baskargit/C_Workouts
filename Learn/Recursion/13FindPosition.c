/*

Using array recursion

https://practice.geeksforgeeks.org/problems/finding-position/0

Some people are standing in a queue. A selection process follows a rule where people standing on even positions 
are selected. Of the selected people a queue is formed and again out of these only people on even position 
are selected. This continues until we are left with one person. Find out the position 
of that person in the original queue.

Input:
5
9
Output:
4
8

*/

#include<stdio.h>

void initializeQueue(int n,int queue[n]);
int position(int n,int queue[n],int queueCount,int lastQueuepos,int currentPosition,int tracker);

int main()
{
    int n;
    scanf("%d",&n);
    int queue[n];
    initializeQueue(n,queue);

    printf("%d\n",position(n,queue,n,1,0,0));
    return 0;
}

int position(int n,int queue[n],int queueCount,int lastQueuepos,int currentPosition,int tracker)
{
    // Base Condition
    if (queueCount == 1)
    {
        return lastQueuepos;
    }

    if (currentPosition < n)
    {
        if (queue[currentPosition])
        {
            ++tracker;
            if (tracker % 2 == 0)
            {
                lastQueuepos = currentPosition + 1;
            }
            else
            {
                queue[currentPosition] = 0;
                --queueCount;
            }
        }
    }
    return position(n,queue,queueCount,lastQueuepos,(currentPosition < n) ? currentPosition + 1 : 0,(currentPosition < n) ? tracker : 0);
}

void initializeQueue(int n,int queue[n])
{
    for (int i = 0; i < n; i++)
    {
        queue[i] = 1;
    }
}