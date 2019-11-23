#include <stdio.h>
#include <string.h>

int main()
{
	int testCaseCount;
    scanf("%d",&testCaseCount);
    
    for(int count=0; count<testCaseCount; count++)
    {
        char string[2001];
        scanf("%s",string);

        for (int start = 0,end = 0; start <= strlen(string); start = ++end)
        {
            for (; string[end] != '\0' && string[end] != '.'; end++);

            for (int k = end - 1; k >= start; k--)
            {
                printf("%c",string[k]);
            }

            printf("%c",(string[end] == '\0' || string[end + 1] == '\0') ? '\0' : '.');
        }

        printf("\n");
    }
    
	return 0;
}
