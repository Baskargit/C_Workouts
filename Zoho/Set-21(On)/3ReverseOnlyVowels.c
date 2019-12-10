#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "smupgxpepmidxowfdsigfn ebwkxpqph";
    // char str[100000];
    // scanf("%[^\n]s",str);

    int i = 0,j = strlen(str) - 1;

    while (i < j && j > i)
    {
        while (i < j && str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U')
        {
            i++;        
        }
        
        while (j > i && str[j] != 'a' && str[j] != 'e' && str[j] != 'i' && str[j] != 'o' && str[j] != 'u' && str[j] != 'A' && str[j] != 'E' && str[j] != 'I' && str[j] != 'O' && str[j] != 'U')
        {
            j--;        
        }

        char temp = str[j];
        str[j] = str[i];
        str[i] = temp;

        i++;
        j--;
    }

    printf("%s\n",str);
    return 0;
}

/*
Input:
smupgxpepmidxowfdsigfn ebwkxpqph

Its Correct output is:
smepgxpipmodxiwfdsegfn ubwkxpqph

And Your Code's output is:
smepgxpipmidxowfdsegfn ubwkxpqph
*/
