/*
  Ex.  INPUT  :  7

    OUTPUT  :

            1
           1 1
          1 2 1
         1 3 3 1
        1 4 6 4 1
       1 5 10 10 5 1
      1 6 15 20 15 6 1

 Ex.  INPUT  :  5

    OUTPUT  :

            1
           1 1
          1 2 1
         1 3 3 1
        1 4 6 4 1
*/

#include <stdio.h>

int main()
{
    int n = 5;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(j >= n - i - 1) 
            {
                if(j == n - i - 1 || j == n -1) {
                    printf("1 ");
                } 
                else {
                    printf("%d ",i);
                }
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}
