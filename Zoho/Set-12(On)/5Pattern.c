#include <stdio.h>

int main()
{
    int n = 6;

    for (int i = 0; i < n; i++)
    {
        printf("%s",(i == 0 || i == 1) ? "  " : "");

        int k = i+1;
        for (int j = 0; j < n - i; j++)
        {
            printf("%d ",k);
            k += n - j;
        }
        printf("\n");
    }
    

    return 0;
}
