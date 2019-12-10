#include <stdio.h>
#include <string.h>

int main()
{
    // 2 : 20
    char str[] = "i.l.l";

    int strlength = strlen(str);
    char newstr[strlength];

    int i = strlength - 1,j = 0,pos = 0,tempj;

    while (i >= 0)
    {
        j = i;

        while (j >= 0 && str[j] != '.' && j--) { }

        tempj = j;

        // Copy the new string
        while (++j <= i && (newstr[pos++] = str[j])) { }
        newstr[pos++] = '.';

        i = --tempj;
    }
    newstr[--pos] = '\0';

    printf("%s\n%s\n",str,newstr);
    
    return 0;
}
