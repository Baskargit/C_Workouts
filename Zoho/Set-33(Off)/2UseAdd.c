/*
2. Find the result subtraction, multiplication, division of two integers using + operator.
Input: 6 and 4
output:
addition 6+4 = 10,    subtraction  6+(-4) = 2,   multiplication = 24,   division = 1

Input : -8 and -4
Output:
addition -8+(-4) = -12,    subtraction  (-8)+(-(-4)) = -4,   multiplication = 32,   division = 2
*/

#include <stdio.h>

int main()
{
    int a = -8 , b = -4;

    int result = 0;
    // Addition
    result = a + b;
    printf("Add : %d\n",result);

    // Subtraction
    result = 0;
    result = a + (-(b));
    printf("Sub : %d\n",result);

    // Multiplication
    result = a;
    for (int i = 1; i < b; i++)
    {
        result += a;
    }
    printf("Mul : %d\n",result);

    // Division
    result = a;
    int i = 0;
    while ()
    {
        
    }
    

    return 0;
}
