/*
   1  
  3 2
 6 5 4
10 9 8 7
10 9 8 7 
 6 5 4 
  3 2 
   1
*/

#include <stdio.h>

int main()
{
    int n = 3;

    int start = 0;
    int till;
    for (int i = 1; i <= n; i++)
    {
        till = start + i;

        for (int j = 1,k = till; j <= n; j++)
        {
            if (j > n - i)
            {
                printf("%d ",k--);
            } else {
                printf(" ");
            }
            
        }
        printf("\n");

        start = till;
    }

    start = till;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1,k = till; j <= n; j++)
        {
            if (j > n - i)
            {
                printf("%d ",k--);
            } else {
                printf(" ");
            }
            
        }
        printf("\n");

        till = till - i;
    }
    
    return 0;
}
