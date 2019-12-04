/*
link : https://www.geeksforgeeks.org/zoho-interview-experience-set-38-on-campus/
Given a number, print all the code that can be formed with z={a=1, .., z=26}.

1123

{1, 1, 2, 3} = aabc

{11, 2, 3} = kbc

{1, 1, 23} = aaw

{11, 23} = kw

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    char num[] = "1124";

    // Print 1 comb
    int i = 0 ,j;
    while (num[i] != '\0')
    {
        printf("%c%c",num[i],(num[i+1] != '\0') ? ',' : '\0');
        i++;
    }
    printf("\n");

    int strlen = i;

    i = 0;    
    j = i + 1;

    // Print 1,2 comb
    while (j < strlen)
    {
        char number[2];
        number[0] = num[i]; number[1] = num[j]; number[2] = '\0';
        int conv = atoi(number);
        bool convflag = false;

        if (conv >= 1 && conv <= 26)
        {
            convflag = true;
            if (i > 0)
            {
                int l = 0;
                while (l < i)
                {
                    printf("%c,",num[l]);
                    l++;
                }   
            }

            printf("%d%c",conv,(num[j+1] != '\0') ? ',' : '\0');
        }

        int k = j+1;
        if (convflag && k < strlen)
        {
            while (num[k] != '\0')
            {
                printf("%c%c",num[k],(num[k+1] != '\0') ? ',' : '\0');
                k++;
            }
        }
        
        printf("\n");
        i = j;
        j = i + 1;
    }

    // Print 2,2 comb
    if (strlen >= 4)
    {
        i = 0;
        j = i + 1;
        bool convflag = false;

        while (j <= strlen)
        {
            char number[2];
            number[0] = num[i]; number[1] = num[j]; number[2] = '\0';
            int conv = atoi(number);

            if (conv >= 1 && conv <= 26)
            {
                printf("%d%c",conv,(num[j+1] != '\0') ? ',' : '\0');
            }

            i = j + 1;
            j = (i == strlen) ? i : i + 1;
        }
        printf("\n");
    }
    
    return 0;
}
