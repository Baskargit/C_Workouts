/*
link : https://practice.geeksforgeeks.org/problems/total-decoding-messages/0

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    int n = 35;
    char encodedmesg[] = "44476317596217857418597538831896433";
    bool isvalidmesg = true;

    int i=0,numofways = 1;
    while (encodedmesg[i] != '\0')
    {
        if (encodedmesg[i] == '0' && encodedmesg[i+1] == '0')
        {
            isvalidmesg = false;
            break;
        } else if (encodedmesg[i] == '0')
        {
            numofways = 0;
        }

        i++;
    }

    isvalidmesg = (encodedmesg[0] == '0' || encodedmesg[i - 1] == '0') ? false : true;

    if (isvalidmesg)
    {

        for (int i = 0; i < n - 1; i++)
        {
            bool nozeros = true;

            for (int l = 0; l < i; l++)
            {
                if (encodedmesg[l] == '0')
                {
                    nozeros = false;
                    break;
                }
                
            }

            if (nozeros && encodedmesg[i] != '0')
            {
                for (int j = i + 1; j <= i+1; j++)
                {
                    bool canincrement = true;
                    char num[2];
                    num[0] = encodedmesg[i]; num[1] = encodedmesg[j]; num[2] = '\0';

                    int convertednum = atoi(num);
                    if (convertednum >= 1 && convertednum <= 26)
                    {
                        // single increment
                        for (int k = j + 1; k < n; k++)
                        {
                            if (encodedmesg[k] == '0')
                            {
                                canincrement = false;
                                break;
                            }
                        }

                        if (canincrement)
                        {
                            ++numofways;

                            // dual check left
                            // 2 (2) 1
                            for (int m = 0; m < i - 2; m++)
                            {
                                num[0] = encodedmesg[m]; num[1] = encodedmesg[m+1]; num[2] = '\0';

                                convertednum = atoi(num);

                                if (convertednum >= 1 && convertednum <= 26)
                                {
                                    printf("dcl : %d ==> %d\n",convertednum,i);
                                    ++numofways;
                                }
                            }
                            
                            // dual check right
                            // 1 (2) 2
                            for (int m = j + 1; m < n - 1; m++)
                            {
                                num[0] = encodedmesg[m]; num[1] = encodedmesg[m+1]; num[2] = '\0';

                                convertednum = atoi(num);

                                if (convertednum >= 1 && convertednum <= 26)
                                {
                                    printf("dcr : %d ==> %d\n",convertednum,i);
                                    ++numofways;
                                }
                                
                            }

                            // 2 (2) 2

                            
                            
                        }                     
                    }
                }
            }
        }
    }
    
    printf("%d\n",numofways);
    
    return 0;
}

/*
Input:
11
23759228973

Its Correct output is:
4

And Your Code's output is:
3

Input:
35
44476317596217857418597538831896433

Its Correct output is:
24

And Your Code's output is:
15

*/