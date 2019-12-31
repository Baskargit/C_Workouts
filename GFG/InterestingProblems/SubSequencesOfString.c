// Print with duplicates

#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int n,totalsubseqcount = 0;
    char string[] = "abcde";
    n = strlen(string);

    for (int i = 0; i < n; i++) // Go till length n
    {
        for (int j = 0; j < n; j++) // iterate till the length
        {
            char buffer[n];
            int pos = 0;

            int tempk = 0;
            for (int k = j; j+i < n && k <= j+i; k++) // 0 to length
            {
                buffer[pos++] = string[k];
                tempk = k;
            }

            if (i != 0)
            {
                pos--;
                int tempos = pos;
                for (int k = tempk; k < n; k++)
                {
                    buffer[tempos++] = string[k];
                    buffer[tempos] = '\0';

                    printf("%s ",buffer);
                    tempos = pos;
                    totalsubseqcount = (strlen(buffer) >= 1) ? totalsubseqcount + 1 : totalsubseqcount;
                }
            }
            else
            {
                buffer[pos] = '\0';
                ++totalsubseqcount;
                printf("%s ",buffer);  
            }
        }
        printf("\n");
    }
    
    printf("Total subseuence count : %d\n",totalsubseqcount);
    return 0;
}
