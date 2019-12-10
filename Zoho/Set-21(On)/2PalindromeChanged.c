#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *buffer,int length);
int ispalindrome(char *buffer,int length);

int main()
{
    int n = 30;
    char buffer[16];

    // convert to string
    sprintf(buffer,"%d",n);
    int length = strlen(buffer);

    // Reverse
    reverse(buffer,length);

    // convert to int
    int temp = atoi(buffer);
    sprintf(buffer,"%d",temp);
    int flag = 1;
        
    for (int i = 0; i < 5; i++)
    {
        n += temp;
        sprintf(buffer,"%d",n);
        if(ispalindrome(buffer,strlen(buffer)))
        {
            flag = 0;
            printf("Yes palindrome : %d\n",n);
            break;
        }
    }

    if(flag) 
    {
        printf("Not palindrome : %d\n",n);
    }
    
    return 0;
}

void reverse(char *buffer,int length)
{
    for (int i = 0,j = length - 1; i < j && j > i; i++,j--)
    {
        char temp = buffer[j];
        buffer[j] = buffer[i];
        buffer[i] = temp;
    }
}

int ispalindrome(char *buffer,int length)
{
    for (int i = 0,j = length - 1; i < j && j > i; i++,j--)
    {
        if(buffer[i] != buffer[j]) {
            return 0;
        }
    }
    return 1;
}



