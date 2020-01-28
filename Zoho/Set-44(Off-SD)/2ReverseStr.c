/*
Reverse the string without disturbing the vowels and space.
*/

#include<stdio.h>
#include<string.h>

void reverseStr(int n,char string[n],int front,int rear);

int main()
{
    char string[] = "baskaran s";
    int strlength = strlen(string);
    reverseStr(strlength,string,0,strlength - 1);
    return 0;
}

void reverseStr(int n,char string[n],int front,int rear)
{
    if (front == rear || front > rear)
    {
        printf("%s\n",string);
        return;
    }
    else
    {
        if (string[front] != 'A' && string[front] != 'E' && string[front] != 'I' && string[front] != 'O' && string[front] != 'U' && string[front] != 'a' && string[front] != 'e' && string[front] != 'i' && string[front] != 'o' && string[front] != 'u' && string[front] != ' ')
        {
            if (string[rear] != 'A' && string[rear] != 'E' && string[rear] != 'I' && string[rear] != 'O' && string[rear] != 'U' && string[rear] != 'a' && string[rear] != 'e' && string[rear] != 'i' && string[rear] != 'o' && string[rear] != 'u' && string[rear] != ' ')
            {
                char temp = string[front];
                string[front] = string[rear];
                string[rear] = temp;
                return reverseStr(n,string,front + 1,rear - 1);
            }
            else
            {
                return reverseStr(n,string,front,rear - 1);
            }
        }
        else
        {
            return reverseStr(n,string,front + 1,rear);
        }
    }
}