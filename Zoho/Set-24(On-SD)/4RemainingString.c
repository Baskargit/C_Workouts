/*
Given an array of characters print the characters that have ‘n’ number of occurrences. 
If a character appears consecutively it is counted as 1 occurrence

*/

// Below version code different from zoho question
// code question : https://practice.geeksforgeeks.org/problems/remaining-string/0
#include <stdio.h>

int main()
{
    // char string[] = "geeksforgeeks";
    // char ch = 'e';
    // int occurences = 2;

    char string[10000];
    scanf("%s",string);
    getchar();
    char ch;
    scanf("%c",&ch);
    int occurences;
    scanf("%d",&occurences);

    int flag = 0;

    if(occurences > 0) 
    {
        int i = 0,count = 0;

        while (string[i] != '\0')
        {
            if(count == occurences) {
                flag = (string[i+1] != '\0') ? 1 : 0;
                break;
            } else if(string[i] == ch) {
                count++;
                i = (count == occurences) ? i : i+1;
            } else {
                i++;
            }
            
        }
        
        if(flag) 
        {
            for (int j = i+1; string[j] != '\0'; j++)
            {
                printf("%c",string[j]);
            }
            printf("\n");
            
        } else {
            printf("\n");
        }
    } 
    else {
        printf("%s\n",string);
    }

    return 0;
}
