#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    int testCaseCount;
    scanf("%d",&testCaseCount);

    for (int i = 0; i < testCaseCount; i++)
    {
        char number[64];
        scanf("%s",number);

        bool result = true;

        for (int j = 0,length = strlen(number) - 1,k = length; j < length; j++,k--)
        {
            if (*(number + j) != *(number + k)) {
                result = false;
                break;
            }
        }

        printf("%s",(result) ? "Yes\n" : "No\n");
    }
    
    return 0;
}
