// Incorrect solution

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);

    char encodedmesg[n];
    scanf("%s",encodedmesg);

    char isvalidmesg = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (encodedmesg[i] == '0' && encodedmesg[i+1] == '0')
        {
            isvalidmesg = false;
            break;
        }
        else if (encodedmesg[i] == '0' && (encodedmesg[i+1] >= '0' && encodedmesg[i+1] <= '9'))
        {
            isvalidmesg = false;
            break;
        }
    }

    int numberofways = 1;

    if (isvalidmesg)
    {
        for (int i = 0; i < 2; i++)
        {
            bool isvaliddecode = true;
            for (int j = 0; j < n; j++)
            {
                char buffer[n];
                int pos = 0;

                // Copy values untill the max length
                int tempk = 0;
                for (int k = j; j+i < n && k <= j+i; k++)
                {
                    buffer[pos++] = encodedmesg[k];
                    tempk = k;
                }

                if (i != 0)
                {
                    pos--;

                    int tempos = pos;
                    for (int k = tempk; k < n; k++)
                    {
                        buffer[pos++] = encodedmesg[k];
                        buffer[pos] = '\0';
                        printf("%s ",buffer);
                        pos = tempos;

                        int converted = atoi(buffer);
                        if (!(converted >= 1 && converted <= 26))
                        {
                            isvaliddecode = false;
                            break;
                        }
                    }

                    numberofways = (isvaliddecode) ? numberofways + 1 : numberofways;
                }
                else
                {
                    buffer[pos] = '\0';
                    printf("%s ",buffer);
                }    
            }
            printf("\n");
        }
            
    }
    
    
    printf("%d\n",numberofways);
    return 0;
}

/*
11
23759228973

17
12931947845036106

4
2563
*/
