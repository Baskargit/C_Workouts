// https://practice.geeksforgeeks.org/problems/arya-and-the-great-war/0

#include<stdio.h>

int getStabCount(int x);
int getNfromBinary(int x);

int main()
{
    int x;
    scanf("%d",&x);

    printf("%d\n",getStabCount(x));
    return 0;
}

int getStabCount(int x)
{
    return (x > 2) ? getNfromBinary(x) : 1;
}

int getNfromBinary(int x)
{
    return (x) ? (x % 2) ? 1 + getNfromBinary(x/2) : getNfromBinary(x/2) : 0;
}