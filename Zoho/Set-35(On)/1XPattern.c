/*
Given a string of odd length, print the string X format.

Input: 12345

Output:
1       5
  2   4
    3
  2   4
1       5 

*/

#include <stdio.h>
#include <string.h>

int main()
{
    char string[] = "geeksforgeeks";
    int n = strlen(string);

    if (n % 2 != 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == i || j == n - i - 1)
                {
                    printf("%c",string[j]);
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        
    }
    
    return 0;
}
