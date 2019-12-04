/*
A number is said to be twisted prime if it is a prime number and reverse of the number is also a prime number.

Input : 97
Output : Twisted Prime Number

Explanation: 97 is a prime number
and its reverse 79 is also a prime
number.

*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isprime(int n)
{
    for (int i = 2; i <= n/2; i++)
    {
        if (n%i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int num = 43;
    char number[16];
    sprintf(number,"%d",num);
    int length = strlen(number);

    printf("%s => len = %d\n",number,length);

    int twistednum = 0;
    int multiplier = 1;
    for (int i = 0; i < length; i++)
    {
        twistednum += (number[i] - '0') * multiplier;
        multiplier *= 10;
    }

    printf("twistednum = %d\n",twistednum);
    
    printf("%s\n",(isprime(num) && isprime(twistednum)) ? "Yes" : "No");
        
    return 0;
}


