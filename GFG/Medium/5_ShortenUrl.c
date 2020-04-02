// https://practice.geeksforgeeks.org/problems/design-a-tiny-url-or-url-shortener/0

#include<stdio.h>

void printShortenUrl(int n,char chars[]);

int main()
{
	int testCaseCount;
    scanf("%d",&testCaseCount);
    
    for(int count=0; count<testCaseCount; count++)
    {
        int n;
        scanf("%d",&n);
        
        char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

        printShortenUrl(n,chars);
        printf("\n");
        printf("%d\n",n);
    }
    
	return 0;
}

void printShortenUrl(int n,char chars[])
{
    if (n)
    {
        printShortenUrl(n/62,chars);
        printf("%c",chars[n % 62]);
    }
    else
    {
        return;
    }
}