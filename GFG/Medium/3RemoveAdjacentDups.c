/*
Time taken to solve : 28min
Execution time : 0.01S
https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates/0

Input:
2
geeksforgeek
acaaabbbacdddd

Output:
gksforgk
acac

*/

#include<stdio.h>
#include<string.h>

int main()
{
    char str[51];
    scanf("%s",str);

    int n = strlen(str),flag = 1,pos = 0,counter = 0;

    char previouschar = '\0';

    while (flag)
    {
        for (int i = 0; i < n; i++)
        {
            if (str[i] != str[i+1] && str[i] != previouschar)
            {
                str[pos++] = str[i]; 
            }
            else
            {
                counter++;
            }
            
            previouschar = str[i];
        }

        str[pos] = '\0';
        n = pos;
        flag = counter;

        pos = counter = 0;
        previouschar = '\0';
    }
    
    printf("%s\n",str);
    
    return 0;
}

/*
Corner cases

Input:
mississipie

Its Correct output is:
mpie

And Your Code's output is:
miiipie

Input:
grrrrrrrrrrrrrgr

Its Correct output is:
r

And Your Code's output is:

*/