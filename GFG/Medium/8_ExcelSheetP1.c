// https://practice.geeksforgeeks.org/problems/excel-sheet/0/

#include<stdio.h>

void printColumnTitle(unsigned int n);

int main()
{
    unsigned int n;
    scanf("%d",&n);

    printColumnTitle(n);
    printf("\n");
    return 0;
}

void printColumnTitle(unsigned int n)
{
    if (n > 26)
    {
        printColumnTitle((n % 26 == 0) ? n/26 - 1 : n/26);
        printf("%c",'@' + ((n % 26) ? n % 26 : 26));   
    }
    else
    {
        printf("%c",'@' + ((n) ? n : 26));
        return;
    }
}