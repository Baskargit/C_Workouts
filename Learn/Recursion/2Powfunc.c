#include<stdio.h>

unsigned long long int powof(int base,int power);

int main()
{
    int x = 2,y = 3;
    printf("pow(%d^%d) = %llu\n",x,y,powof(x,y));
    
    return 0;
}

unsigned long long int powof(int base,int power)
{
    if (power == 0)
    {
        return 1;
    }
    
    return base * powof(base,power - 1);
}
