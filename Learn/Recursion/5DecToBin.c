#include<stdio.h>

void printBinary(int num);

int main()
{
    int num = 848465;
    printBinary(num);
    printf("\n");
    return 0;
}

void printBinary(int num)
{
    if (num == 1)
    {
        printf("1");
        return;
    }
    
    printBinary(num/2);
    printf("%d",num % 2);
}