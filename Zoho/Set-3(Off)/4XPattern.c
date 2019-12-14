// 6:27
/*
Input: 12345
Output:
1       5
  2   4
    3
  2  4
1      5
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char str[] = "zohocorporation";
    int n = strlen(str);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ",(j == i || j == n - i - 1) ? str[j] : ' ');
        }
        printf("\n");
    }
    
    return 0;
}

