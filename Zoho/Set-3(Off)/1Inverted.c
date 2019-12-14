#include<stdio.h>

int main()
{
    char ch[100];
    int count[100];
    int counter = 0;

    char c = getchar();
    for (int i = 0; c != '\n'; i++)
    {
        ch[i] = c;
        scanf("%d",&count[i]);
        c = getchar();
        counter++;
    }
    
    for (int i = 0; i < counter; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            printf("%c",ch[i]);   
        }
    }
    printf("\n");
    
    return 0;
}
