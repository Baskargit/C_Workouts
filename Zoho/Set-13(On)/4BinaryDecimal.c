#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 2019;

    int i = 1,flag,j,pos = 0;
    int nums[n/2];
    while (i <= n)
    {
        flag = 1;

        char buffer[64];
        sprintf(buffer,"%d",i);

        j = 0;
        while (buffer[j] != '\0')
        {
            if(buffer[j] == '1' || buffer[j] == '0') 
            {
                j++;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        
        if(flag) {
            printf("%d ",i);
            nums[pos++] = i;
        }

        i++;
    }
    printf("\n");

    return 0;
}