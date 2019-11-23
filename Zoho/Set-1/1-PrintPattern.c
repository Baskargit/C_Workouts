#include <stdio.h>
#include <string.h>

int main()
{
    char string[] = "BASKARANS.S";

    int length = strlen(string);
    
    if (length%2 != 0)
    {
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
            {
                printf("%c",(i == j || j == (length - 1) - i) ? string[j] : ' ');
            }
            printf("\n");
        }
    }
    
    return 0;
}
