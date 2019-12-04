/*
3. Two strings of equal length will be given. Print all the adjacent pairs which are not equal.

Input: asdfghij and adsfgijh

Output: sd-ds, hij-ijh

*/

#include <stdio.h>

int main()
{
    char s1[] = "asdfghi12";
    char s2[] = "as38jkjj1";

    int i = 0;
    int front,rear;
    while (s1[i] != '\0')
    {
        while (s1[i] == s2[i]) { i++; }
        
        front = rear = i;
        while (s1[i] != s2[i] && s1[i] != '\0') { rear++; i++; }
        
        if (rear > 0)
        {
            for (int j = front; j < rear; j++)
            {
                printf("%c",s1[j]);
            }
            printf("-");
            for (int j = front; j < rear; j++)
            {
                printf("%c",s2[j]);
            }
            printf(" ");
        }

        front = rear = 0;
    }

    printf("\n");
    
    return 0;
}
