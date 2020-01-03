/*
Input: Hexadecimal = 1AC5
Output: Binary = 0001101011000101
Explanation:
    Equivalent binary value of 1: 0001
    Equivalent binary value of A: 1010
    Equivalent binary value of C: 1100
    Equivalent binary value of 5: 0101

Input: Hexadecimal = 5D1F
Output: Binary = 0101110100011111
*/

#include<stdio.h>

void printBinary(char *num);

int main()
{
    char number[] = "5D1F";
    printBinary(number);

    return 0;
}

void printBinary(char *num)
{
    if (*num)
    {
        switch (*num)
        {
            case '0':
                printf("0");
                break;
            case '1':
                printf("0001");
                break;
            case '2':
                printf("0010");
                break;
            case '3':
                printf("0011");
                break;
            case '4':
                printf("0100");
                break;
            case '5':
                printf("0101");
                break;
            case '6':
                printf("0110");
                break;
            case '7':
                printf("0111");
                break;
            case '8':
                printf("1000");
                break;
            case '9':
                printf("1001");
                break;
            case 'A':
                printf("1010");
                break;
            case 'B':
                printf("1011");
                break;
            case 'C':
                printf("1100");
                break;
            case 'D':
                printf("1101");
                break;
            case 'E':
                printf("1110");
                break;
            case 'F':
                printf("1111");
                break;
            
            default:
                break;
        }
        return printBinary(++num);
    }
    
    printf("\n");
    return;
}
