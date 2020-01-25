/*
Q.no.2
Given N. print the Latin Matrix. 
condition:  must not use strings(aka character literals), arrays (both 1D and 2D), inbuilt functions(like rotate).

(say N = 3)
A  B  C
C  A  B
B  C  A

1 2 3
3 1 2 
2 3 1

(say N = 5)
1 2 3 4 5
5 1 2 3 4
4 5 1 2 3 
3 4 5 1 2
2 3 4 5 1


*/

#include<stdio.h>
#include<stdbool.h>

void printLatinInt(int n);
void printLatinChar(int n);

int main()
{
    int n = 3;

    printLatinInt(n);
    printLatinChar(n);
    return 0;
}

void printLatinChar(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i)
        {
            for (int j = n - i + 1; j <= n; j++)
            {
                printf("%c ",64 + j);
            }
            for (int j = 1; j <= n - i; j++)
            {
                
                printf("%c ",64 + j);
            }
        }
        else
        {
            for (int j = 1; j <= n; j++)
            {
                printf("%c ",64 + j);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void printLatinInt(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i)
        {
            for (int j = n - i + 1; j <= n; j++)
            {
                printf("%d ",j);
            }
            for (int j = 1; j <= n - i; j++)
            {
                
                printf("%d ",j);
            }
        }
        else
        {
            for (int j = 1; j <= n; j++)
            {
                printf("%d ",j);
            }
        }
        printf("\n");
    }
    printf("\n");
}