/*
https://www.geeksforgeeks.org/divide-two-integers-without-using-multiplication-division-mod-operator/

Divide two integers without using multiplication, division and mod operator

*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int dividend = 12 , divisor = 12,result = 0;

    int flag = (dividend >= 0 && divisor >= 0 || dividend < 0 && divisor < 0) ? 1 : 0;

    dividend = (dividend >=0 ) ? dividend : abs(dividend);
    divisor = (divisor >= 0) ? divisor : abs(divisor);

    while ((divisor > 0 && dividend > 0) && dividend >= divisor)
    {
        dividend -= divisor;
        result++;
    }
    
    printf("%c%d\n",(flag || result == 0) ? '\0' : '-',result);
    return 0;
}
