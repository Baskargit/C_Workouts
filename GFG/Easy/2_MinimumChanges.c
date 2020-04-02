// https://practice.geeksforgeeks.org/problems/minimum-changes-to-make-all-substrings-distinct/0

#include<stdio.h>

int main()
{
    int count[26] = {0},minmumNoOfChanges = 0;

    char input[26];
    scanf("%s",input);

    int i = -1;

    while (input[++i])
    {
        if (count[input[i] - 'a'])
        {
            ++minmumNoOfChanges;
        }
        else
        {
            count[input[i] - 'a'] = 1;
        }
    }
    
    printf("%d\n",minmumNoOfChanges);
    return 0;
}
