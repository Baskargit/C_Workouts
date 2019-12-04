/*
Given two Strings s1 and s2, remove all the characters from s1 which is present in s2.

Input: s1=”expErIence”, s2=”En”
output: s1=”exprIece”

*/

#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = "expErIence";
    char s2[] = "En";

    int s1length = strlen(s1);

    int i = 0;
    while (s2[i] != '\0')
    {
        int j = 0;
        while (j < s1length)
        {
            if (s1[j] == s2[i])
            {
                s1[j] = '\0';
            }
            j++;
        }
        i++;
    }

    i=0;
    while (i < s1length)
    {
        printf("%c",s1[i++]);
    }
    printf("\n");
    
    return 0;
}
