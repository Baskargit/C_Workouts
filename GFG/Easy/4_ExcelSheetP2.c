// https://practice.geeksforgeeks.org/problems/excel-sheet-part-2/0/

#include<stdio.h>
#include<string.h>

unsigned long int getColumnNumber(int n,char input[n],int currentN,unsigned long int multiplier);

int main()
{
    char input[7];
    scanf("%s",input);
    int length = strlen(input);
    printf("Str len : %d\n",length);

    printf("%lu\n",getColumnNumber(length,input,length - 1,0));
    return 0;
}

unsigned long int getColumnNumber(int n,char input[n],int currentN,unsigned long int multiplier)
{
    if (currentN + 1 == n)
    {
        return (input[currentN] - '@') + getColumnNumber(n,input,currentN - 1,26);
    }
    else if (currentN >= 0)
    {
        return (multiplier * (input[currentN] - '@')) + getColumnNumber(n,input,currentN - 1,multiplier * 26);
    }
    else
    {
        return 0;
    }
}