/*
Given two strings where first string may contain wild card characters and second string is a normal string. 
Write a function that returns true if the two strings match. 
The following are allowed wild card characters in first string.

* --> Matches with 0 or more instances of any character 
      or set of characters.
? --> Matches with any one character.

*/

// Not completed

#include<stdio.h>

int main()
{
    char s1[] = "ge?ks*";
    char s2[] = "geeksforgeeks";

    int i=0,j=0;
    int previousindex = -1,prei = 0;

    while (s1[i] != '\0')
    {
        if(s1[i] == '*' || s1[i] == '?') 
        {
            if(s2[j] != '\0') {
                i++;
                j++;
            }
            else
            {
                previousindex = -1;
                break;
            }
            
        }
        else
        {
            while (s2[j] != '\0')
            {
                if(s2[j] == s1[i] && j > previousindex) 
                {
                    previousindex = j;
                    prei = i;
                    j++;
                    break;
                }
                else
                {
                    j++;
                }
            }
        }
        i++;
    }
    

    return 0;
}
