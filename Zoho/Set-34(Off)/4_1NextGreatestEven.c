// https://www.geeksforgeeks.org/find-next-greater-number-set-digits/
// https://practice.geeksforgeeks.org/problems/next-greater-even-number/0

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char num[] = "534976";
    int length = strlen(num);
    bool isNGEexists = false;

    for (int i = length - 1; i >= 0; i++)
    {
        if (num[i] < num[i+1])
        {
            isNGEexists = true;
            break;
        }
    }

    if (isNGEexists)
    {
        int d,d1;

        for (int i = length - 1; i >= 0; i++)
        {
            if (num[i] < num[i+1])
            {
                isNGEexists = true;
                break;
            }
        }
    }
    
    printf("-1\n");

    return 0;
}
