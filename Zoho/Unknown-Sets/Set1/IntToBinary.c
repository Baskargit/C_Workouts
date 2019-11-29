#include <stdio.h>

int main()
{
    int n = 12875546;

    int bitlength = 32;
    char binary[bitlength + 1];
    int counter = 0;

    while (counter < bitlength)
    {
        binary[counter++] = 48;
    }

    binary[counter] = '\0';
    
    while (n != 0)
    {
        binary[--counter] = (n % 2) + 48;
        n = n/2;
    }
    
    printf("%s\n",binary);

    return 0;
}
