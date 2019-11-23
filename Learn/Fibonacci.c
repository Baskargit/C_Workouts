#include <stdio.h>

int main(int argc, char const *argv[])
{
    long int num = 40;

    long int a = 0;
    long int b = 1;
    long int c;

    for (int i = 1; i <= num; i++)
    {
        printf("%ld ",a);
        c = a + b;
        a = b;
        b = c;
    }
    
    printf("\n");


    return 0;
}
