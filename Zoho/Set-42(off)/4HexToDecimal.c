#include<stdio.h>

unsigned long long int printDecimal(int n,char hex[],int power);
unsigned long long int powof(int base,int power);

int main()
{
    char hex[] = "794A1";
    int length = sizeof(hex) - 2;

    printf("%llu\n",printDecimal(length,hex,0));   
    return 0;
}

unsigned long long int printDecimal(int n,char hex[],int power)
{
    if (n >= 0)
    {
        return powof(16,power) * ((hex[n] >= '0' && hex[n] <= '9') ? hex[n] - '0' : 5 - ('F' - hex[n]) + 10) + printDecimal(--n,hex,++power);
    }
    
    return 0;
}

unsigned long long int powof(int base,int power)
{
    return (power == 0) ? 1 : base * powof(base,--power);
}