#include <stdio.h>

int fib(int n)
{
    if (n <= 1)
    {
        printf("computing base case fib(%d)\n",n);
        return n;
    }

    printf("computing fib(%d)\n",n);
    return fib(n - 1) + fib(n-2);
}


int main()
{
    int n = 5;
    printf("%d\n",fib(n));
    return 0;
}
