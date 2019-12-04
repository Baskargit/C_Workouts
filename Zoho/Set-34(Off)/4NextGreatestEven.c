#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isdigitssame(int *ndigitscount,unsigned long long int newn);

int main()
{
    unsigned long long int n = 846649841;

    unsigned long long int newn = n;

    // calculate the digits count
    int ndigitscount[10];
    for (int i = 0; i < 10; i++)
    {
        // set initial values to zero
        ndigitscount[i] = 0;
    }
    
    char number[64];
    sprintf(number,"%lld",n);

    // count the n digits count
    int i = 0;
    while (number[i] != '\0')
    {
        ndigitscount[number[i] - '0']++;
        i++;
    }
    
     unsigned long long int nplusn = n + n;
    while (newn++ && newn < nplusn)
    {
        if (isdigitssame(ndigitscount,newn) && newn % 2 == 0)
        {
            printf("%lld\n",newn);
            return 0;
        }
    }
    
    printf("-1\n");
    return 0;
}

bool isdigitssame(int *ndigitscount,unsigned long long int newn)
{
    char number[64];
    sprintf(number,"%lld",newn);

    // calculate the digits count
    int newndigitscount[10];
    for (int i = 0; i < 10; i++)
    {
        // set initial values to zero
        newndigitscount[i] = 0;
    }

    int i = 0,j;
    while (number[i] != '\0')
    {
        newndigitscount[number[i] - '0']++;
        i++;
    }

    // check whether count matches or not
    i = 0;
    while (i < 10)
    {
        if (ndigitscount[i] != newndigitscount[i])
        {
            return false;
        }
        i++;
    }
    
    return true;
}