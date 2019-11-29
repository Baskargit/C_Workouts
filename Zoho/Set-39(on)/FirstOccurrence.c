#include <stdio.h>

int main()
{
    char s1[] = "ZOHOCORPORATION";
    char s2[] = "PORT";

    int minindex = 0;
    int maxindex = 0;

    int i = 0;
    while (s2[i] != '\0')
    {
        int j = 0;
        while (s1[j] != '\0') 
        {
            if(s1[j] == s2[i]) 
            {
                if (j > maxindex) {
                    maxindex = j;
                    break;
                } else if(minindex == 0) {
                    minindex = j;
                    break;
                } else if (j < minindex) {
                    minindex = j;
                    break;
                }
            }
            j++;
        }
        i++;
    }

    for (int i = 0; i <= maxindex; i++)
    {
        printf("%c",s1[i]);
    }

    printf("\n");
    return 0;
}
