/*
Input: PROGRAM
Output:
              G
            GR
          GRA
       GRAM
     GRAMP
   GRAMPR
GRAMPRO

            G                                       A
          GR                                      AT  
        GRA                                     ATR
      GRAM
    GRAMP
  GRAMPR
GRAMPRO

**/

#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "CGXWWHUFTG";
    int length = strlen(s);

    char newstring[length];

    if(length % 2 != 0) 
    {
        int pos = 0;
        int middle = length/2;

        newstring[pos++] = s[middle];

        // right part
        for (int i = middle + 1; i < length; i++)
        {
            newstring[pos++] = s[i];
        }
        
        // left part
        for (int i = 0; i < middle; i++)
        {
            newstring[pos++] = s[i];
        }
        newstring[pos] = '\0';

        // Print the pattern
        int printed = 0;
        for (int k = 0; k < length; k++)
        {

            for (int i = 1; i <= length*2-k*2-2; i++)
            {
                printf("0");
            }

            for (int j = 0; j <= k; j++)
            {
                printf("%c",newstring[j]);
                printed++;
            }
            
            printf("\n");
        }
        
        
    } 
    else 
    {
        printf("\n");
    }

    return 0;
}

/**
 Input:
CGXWWHUFTG

Its Correct output is:
                  H$                HU$              HUF$            HUFT$          HUFTG$        HUFTGC$      HUFTGCG$    HUFTGCGX$  HUFTGCGXW$HUFTGCGXWW$

*/