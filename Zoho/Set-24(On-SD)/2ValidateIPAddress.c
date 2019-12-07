/*
Corner cases
1-> decimal count
2-> dot count
3-> non number characters

For Input:
8
222.111.111.111
5555..555
0000.0000.0000.0000
1.2.3.04
11a.2a1
1.1.1
1.1.1.1
9999999
Your Output is:
1
0
0
0
0
0
1
0
*/

#include <stdio.h>
#include <stdlib.h>

int isValid(char *ip);

int main()
{
    char ip[] = "0.2.3.a4";

    printf("%d\n",isValid(ip));
    return 0;
}

int isValid(char *ip)
{
    int i=0,j=0,decimalcount = 0,dotcount = 0;
    int proceed = 1;

    while (ip[i] != '\0')
    {
        char number[50];
        int counter = 0;

        int digitscount = 0;
        j = i;
        while (ip[j] != '.' && ip[j] != '\0')
        {
            digitscount = (ip[j] >= '0' && ip[j] <= '9' && digitscount >= 0) ? digitscount + 1 : -1;
            number[counter++] = ip[j];
            j++;
        }
        number[counter] = '\0';

        dotcount = (ip[j] == '.') ? dotcount + 1 : dotcount;
        
        proceed = (digitscount>=1 && digitscount <= 3) 
                    ? (digitscount > 1 && number[0] == '0') ? 0 : 1 
                    : 0 ;

        if(proceed) 
        {
            int convertednum = atoi(number);

            if(!(convertednum >= 0 && convertednum <= 255)) 
            {
                return 0;
            }
            decimalcount++;
        } 
        else {
            return 0;
        }

        i = (ip[j] != '\0') ? j + 1 : j;
    }
    
    return decimalcount == 4 && dotcount == 3;
}
