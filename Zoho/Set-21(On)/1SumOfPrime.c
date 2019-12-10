// Wrong
// Given a number N. Find if it can be expressed as sum of two prime numbers.


#include <stdio.h>

int main()
{
    int n = 930887;

    int flag = 0;

    for (int i = 2; i < n; i++)
    {
        if(n % i == 0) {
            printf("%d\n",i);
            flag = 1;
            break;
        }
    }

    printf("%s\n",(flag) ? "Yes" : "No");
    
    return 0;
}
