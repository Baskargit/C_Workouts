#include<stdio.h>

unsigned long long int powof(int base,int power);
unsigned long long int binaryToDecimal(int n,char *num,int pos);

int main()
{
    char binary[] = "100011";
    printf("%llu\n",binaryToDecimal(sizeof(binary) - 2,binary + sizeof(binary) - 2,0));

    return 0;
}

unsigned long long int binaryToDecimal(int n,char *num,int pos)
{
    return (n >= 0) ? ((*num == '1') ? powof(2,pos) : 0) + binaryToDecimal(--n,--num,++pos) : 0;
}

unsigned long long int powof(int base,int power)
{
    return (power == 0) ? 1 : base * powof(base,power - 1);
}