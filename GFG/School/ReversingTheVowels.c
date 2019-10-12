#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
	int totalTestCases;
    scanf("%d",&totalTestCases);
    
    for(int testCase = 1; testCase <= totalTestCases; testCase++)
    {
        char inputString[1024];
        scanf("%s",inputString);

        char vowels[1024];
        int j = 0;
        int inputLength = strlen(inputString);
        for (int i = 0; i < inputLength; i++)
        {
            if (*(inputString + i) == 'a' || *(inputString + i) == 'e' || *(inputString + i) == 'i' || *(inputString + i) == 'o' || *(inputString + i) == 'u' ||
                *(inputString + i) == 'A' || *(inputString + i) == 'E' || *(inputString + i) == 'I' || *(inputString + i) == 'O' || *(inputString + i) == 'U')
            {
                *(vowels + j++) = *(inputString + i);
            }
            
        }
        vowels[j] = '\0';

        for (int i = 0; i < inputLength; i++)
        {
            if (*(inputString + i) == 'a' || *(inputString + i) == 'e' || *(inputString + i) == 'i' || *(inputString + i) == 'o' || *(inputString + i) == 'u' ||
                *(inputString + i) == 'A' || *(inputString + i) == 'E' || *(inputString + i) == 'I' || *(inputString + i) == 'O' || *(inputString + i) == 'U')
            {
                *(inputString + i) = *(vowels + --j);
            }
        }

        printf("%s\n",inputString);
    }
    
	return 0;
}
