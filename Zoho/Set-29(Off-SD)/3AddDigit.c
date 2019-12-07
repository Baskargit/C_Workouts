/*
adding a digit to all the digits of a number eg 
digit=4, 
number = 2875, 
o/p= 612119
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char number[] = "128596";
    int digit = 4;

    char newnumber[256];
    int counter = 0;

    for (int i = 0; number[i] != '\0'; i++)
    {
        char temp[1];
        temp[0] = number[i]; temp[1] = '\0';

        char buffer[2];
        int num = atoi(temp);

        sprintf(buffer,"%d",num+digit);

        int bufferlength = strlen(buffer);
        for (int j = 0; j < bufferlength; j++)
        {
            newnumber[counter++] = buffer[j];
        }
    }
    newnumber[counter] = '\0';

    printf("%s\n",newnumber);
    
        
    return 0;
}
