#include <stdio.h>

void Recursion(int a)
{
    // Base case
    if (a > 5)
    {
        return;
    }
    
    printf("B=%d\n",a);
    Recursion(++a);
    printf("A=%d\n",a);
}

int main(int argc, char const *argv[])
{
    Recursion(0);   
    return 0;
}
