#include<stdio.h>

unsigned int sumOfFirstN(unsigned int n,unsigned int currentN);

int main()
{
    unsigned int n;
    scanf("%d",&n);
    printf("Sof of first %d natural number is : %d\n",n,sumOfFirstN(n,1));
    return 0;
}

unsigned int sumOfFirstN(unsigned int n,unsigned int currentN)
{
    return (currentN <= n) ? currentN + sumOfFirstN(n,currentN + 1) : 0;
}