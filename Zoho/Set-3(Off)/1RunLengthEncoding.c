#include<stdio.h>

char *encode(char *src)
{
    int i = 0;
    
    while(src[i] != '\0')
    {
        int count = 1;
        int j = i;
        
        while(src[++j] == src[i] && (++count));
        
        printf("%c%d",src[i],count);
        i = j;
    }

    printf("\n");
    return '\0';
}    

int main()
{
    encode("x");
    return 0;
}
