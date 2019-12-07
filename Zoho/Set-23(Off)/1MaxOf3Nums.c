#include <stdio.h>

int main()
{
    int a = 5 , b = 4 , c = 5 , max;

    max = (a >= b)
            ? (a > c) ? a : c
            : (b > c) ? b : c;

    printf("%d\n",max);

    return 0;
}
