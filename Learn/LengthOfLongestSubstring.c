#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool HasLongestSubString(char *substring);

int main(int argc, char const *argv[])
{
    printf("Enter a string to get the longest Substring\n");
    char string[2048];
    scanf("%s",string);

    int n = strlen(string);

    char substring[n + 1];
    char longestSubstring[n + 1];
    int pos = 0;

    bool res = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            for (int k = j; k <= j + i; k++)
            {
                // Print Substring
                printf("%c",string[k]);
                substring[pos++] = string[k];
            }
            printf(" ");
            substring[pos] = '\0';

            // Check whether 'Longest Substring' present in the current substring
            res = HasLongestSubString(substring);
            if (res) {
                strncpy(longestSubstring,substring,strlen(substring));
                longestSubstring[pos] = '\0';
                break;
            }

            // pos = 0;
        }
        pos = 0;
        printf("\n");
    }

    // Print result
    printf("Length Of Longest Substring is :%ld\n",strlen(longestSubstring));
    printf("Longest Substring is :%s\n",longestSubstring);
    
    return 0;
}

bool HasLongestSubString(char *substring)
{
    int length = strlen(substring);

    for (int i = 0; i < length; i++)
    {
        for (int j = i+1; j < length; j++)
        {
            if (*(substring + i) == *(substring + j))
            {
                return false;
            }   
        }
    }

    return true;
}
