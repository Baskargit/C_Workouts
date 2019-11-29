#include <stdio.h>

void printbinary(int n);

int main()
{
    int n = 481164984;

    printbinary(n);
    printf("\n");
    return 0;
}

void printbinary(int n)
{
    if (n == 0)
    {
        return;
    }
    int remainder = n % 2;
    printbinary(n/2);
    printf("%d",remainder);
}
