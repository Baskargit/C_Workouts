/*
1. Print longest sequence between same character

Ex I/p abcccccbba

O/p 8 (from a to a)

I/p aaaaaaaa

O/p 6

Input:
JvIrhHTnFnyIpDKgcvjrfkmjGBUobEfmZNDgvYWCNWMEAZKCWUvcGHlmKfdMKiAJxGsuEoWsklWKkjOgdkiJtuyebBsLlSX

Its Correct output is:
82

And Your Code's output is:
75

*/

#include <stdio.h>
#include <string.h>

int main()
{
    char string[] = "JvIrhHTnFnyIpDKgcvjrfkmjGBUobEfmZNDgvYWCNWMEAZKCWUvcGHlmKfdMKiAJxGsuEoWsklWKkjOgdkiJtuyebBsLlSX";
    int stringlen = strlen(string);

    int maxcharsequence = -1;

    for (int i = 0; i < stringlen - 1; i++)
    {
        int lastfound = -1;
        
        for (int j = i + 1; j < stringlen; j++)
        {
            if (string[j] == string[i])
            {
                lastfound = j;   
            }
        }

        maxcharsequence = (lastfound - i == 1 && lastfound - i > maxcharsequence)
                            ? 0 
                            : (lastfound - i > maxcharsequence) ? (lastfound - i) - 1 : maxcharsequence;

    }
    
    printf("%d\n",maxcharsequence);
    
    return 0;
}
