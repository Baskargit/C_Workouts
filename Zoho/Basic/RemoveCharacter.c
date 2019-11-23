#include <stdio.h>
#include <string.h>

int main()
{
	int testCaseCount;
    scanf("%d",&testCaseCount);
    
    for(int count=0; count<testCaseCount; count++)
    {
        char s1[51];
        char s2[51];

        // Using scanset to accept space
        scanf("%s[^\n]",s1);
        scanf("%s[^\n]",s2);
        int s1OriginalLength = strlen(s1);

        // Remove s2 characters from s1
        for (int i = 0; i < strlen(s2); i++)
        {
            for (int j = 0; j < s1OriginalLength; j++)
            {
                if (s1[j] != '\0' && s2[i] == s1[j])
                {
                    s1[j] = '\0';
                }
            }
            
        }

        // Print s1
        for (int i = 0; i < s1OriginalLength; i++)
        {
            if (s1[i] != '\0')
            {
                printf("%c",s1[i]);
            }
        }

        printf("\n");
    
    }
    
	return 0;
}