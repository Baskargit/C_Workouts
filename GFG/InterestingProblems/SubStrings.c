#include<stdio.h>
#include<string.h>

int main()
{
    int n;

    char string[] = "abcd";
    n = strlen(string);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = j; j+i < n && k <= j+i; k++)
            {
                printf("%c",string[k]);
            }
            printf(" ");
        }
        printf("\n");
    }
    

    return 0;
}
