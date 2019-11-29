/*
link : https://www.geeksforgeeks.org/zoho-interview-experience-set-38-on-campus/
input : aaabbcc

output : abc
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char string[] = "aaabbcczZZZ";
    int length = strlen(string);

    int i = 0;
    while (i < length)
    {
        if (string[i] != '\0')
        {
            int j = i+1;

            while (j < length)
            {
                if (string[j] == string[i])
                {
                    string[j] = '\0';
                }
                j++;
            }
            
        }
        i++;
    }

    i = 0;
    while (i < length)
    {
        printf("%c",string[i]);
        i++;
    }

    printf("\n");
    return 0;
}
