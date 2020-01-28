#include<stdio.h>

void printBinary(unsigned long long int n);

int main()
{
    unsigned long long int n = 5456464546546546564;
    printBinary(n);
    printf("\n");
    return 0;
}

void printBinary(unsigned long long int n)
{
    if (n == 1)
    {
        printf("1");
        return;
    }
    else
    {
        printBinary(n / 2);
        printf("%lld",n % 2);
    }
}