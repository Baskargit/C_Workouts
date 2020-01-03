/*
Link : https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle/0

Accepted Soln : 0.03S of exec time
*/

#include<stdio.h>

int safeposition(int n,int k,int members[n],int alivecount,int currentN,int currentk);
void initializemembers(int n,int members[n]);

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int members[n];
    initializemembers(n,members);

    printf("Safe : %d\n",safeposition(n,k - 1,members,n,0,0));

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ",members[i]);
    // }printf("\n");
    
    return 0;
}

int safeposition(int n,int k,int members[n],int alivecount,int currentN,int currentk)
{
    if (alivecount == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (members[i]) // alive
            {
                return i+1;
            }
        }
    }
    else
    {
        if (currentk == k && members[currentN] != 0)
        {
            // printf("Killed : %d\n",currentN + 1);
            members[currentN] = 0;
            alivecount = safeposition(n,k,members,alivecount - 1,(currentN + 1 < n) ? currentN + 1 : 0,0);
        }
        else if (currentN + 1 < n)
        {
            alivecount = safeposition(n,k,members,alivecount,currentN + 1,(members[currentN] != 0) ? currentk + 1 : currentk);
        }
        else
        {
            alivecount = safeposition(n,k,members,alivecount,0,(members[currentN] != 0) ? currentk + 1 : currentk);
        }
    }
    
    return alivecount;
}

void initializemembers(int n,int members[n])
{
    for (int i = 0; i < n; i++)
    {
        members[i] = 1;
    } 
}
