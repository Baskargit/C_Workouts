#include <stdio.h>
#include <string.h>

int main()
{
    char num1[100],num2[100],result[101];

    scanf("%s",num1);
    scanf("%s",num2);

    int num1length = strlen(num1);
    int num2length = strlen(num2);

    if(num2length > num1length)
    {
        printf("%s\n",num1);
    }
    else
    {
        result[num1length + 1] = '\0';
        int n1pos = num1length;
        int n2pos = num2length;

        int resultpos = num1length+1;

        int i = n1pos - 1;
        int remainder = 0;
        while (i >= 0)
        {
            int n1 = num1[--n1pos] - '0';
            int n2 = ((n2pos != 0) ? num2[--n2pos] : '0') - '0';

            int sum = n1 + n2 + remainder;
            remainder = 0;
            printf("n1 => %d\n",n1);
            
            if(i > 0) 
            {
                if(sum >= 10) 
                {
                    int lastdigit = sum % 10;
                    result[--resultpos] = lastdigit + '0';
                    remainder = sum/10;
                }else {
                    result[--resultpos] = sum + '0';
                }
            } else {
                if(sum >= 10) 
                {
                    int lastdigit = sum % 10;
                    result[--resultpos] = lastdigit + '0';
                    result[--resultpos] = (sum/10) + '0';
                } else {
                    result[--resultpos] = sum + '0';

                    // have to shift all digits
                    int j = 0,pos = 0;
                    while (j <= num1length + 1)
                    {
                        if(result[j] >= '0' && result[j] <= '9') {
                            result[pos] = result[j];
                            pos++;
                        }
                        j++;
                    }
                    result[pos] = '\0';
                }
                break;
            }
            i--;
        }
        
        printf("%s\n",(strlen(result) <= num1length) ? result : num1);
        
    }
    

    return 0;
}

/*
Corner cases (Remainder tend to be zero after n1+n2+rem)
Input:
832 48

Its Correct output is:
880

And Your Code's output is:
980

Input:
999 1

Its Correct output is:
999

And Your Code's output is:
1000

*/