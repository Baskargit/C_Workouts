#include <stdio.h>

int main()
{
    int n = 3;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < n - i -1)
            {
                printf(" ");
            } else {
                printf("* ");
            }   
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (j > n - i -1)
            {
                printf(" ");
            } else {
                printf("* ");
            }   
        }
        printf("\n");
    }
    
    return 0;
}
