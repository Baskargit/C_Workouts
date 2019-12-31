#include<stdio.h>

void printReverse(char *str);
void reverseString(int front,int rear,char str[]);

int main()
{
    char str[] = "Hello World!!!";

    printReverse(str);
    printf("\n");

    reverseString(0,sizeof(str) - 2,str);
    printf("Reversed : %s\n",str);
    return 0;
}

void reverseString(int front,int rear,char str[])
{
    if (!(front < rear && rear > front))
    {
        return;
    }
    
    char temp = str[front];
    str[front] = str[rear];
    str[rear] = temp;
    reverseString(front + 1,rear - 1,str);
}

void printReverse(char *str)
{
    if (*str == '\0')
    {
        return;
    }
    
    char c = *str;
    printReverse(++str);
    printf("%c",c);
}
