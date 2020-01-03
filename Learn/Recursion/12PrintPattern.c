/*
3:27
https://practice.geeksforgeeks.org/problems/print-pattern/0
*/

#include<stdio.h>

void printPattern(int givenN,int currentN,int recurredN);

int main()
{
    int n;
    scanf("%d",&n);

    printPattern(n,n,1);
    printf("\n");
    return 0;
}

void printPattern(int givenN,int currentN,int recurredN)
{
    if (currentN > 0) 
    {
        if (currentN <= givenN) {
            printf("%d ",currentN);
            return printPattern(givenN,(recurredN) ? currentN - 5 : currentN + 5,recurredN);
        } else {
            return;
        }
    }
    else {
        printf("%d ",currentN);
        return printPattern(givenN,currentN + 5,0);
    }   
}
