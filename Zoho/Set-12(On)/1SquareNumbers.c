#include <stdio.h>

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);

    int i = a;
    int prevj = 1;
    while (i <= b)
    {
        for (int j = prevj; j*j <= i; j++)
        {
            if(j*j == i) {
                printf("%d ",j*j);
                prevj = j;
                break;
            }
        }
        i++;
    }
    
    printf("\n");
    return 0;
}
