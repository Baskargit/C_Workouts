#include <stdio.h>
#include <string.h>

int main()
{
    char input[] = "RAT";
    int strLength = strlen(input);

    int middle = strLength/2;
    char ordered[strLength + 1];
    int counter = 0;

    // Instead of shifting
    for (int i = middle; i < strLength; i++)
    {
        ordered[counter++] = input[i];
    }

    for (int i = 0; i < middle; i++)
    {
        ordered[counter++] = input[i];
    } 
    
    ordered[counter] = '\0';
    counter = 0;
    
    // Print the ordered string
    for (int i = 0 , j =(strLength + (strLength - 1)) - 2; i < strLength; i++,j-=2)
    {
        for (int k = 0; k < (strLength + (strLength - 1)) - i; k++)
        {
            printf("%c",(k > j) ? ordered[counter++] : ' ');
        }
        
        counter = 0;
        printf("$");
    }

    printf("\n");
    

    return 0;
}
