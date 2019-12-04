/*
5. From the input sentence given, find the strings which are not palindrome and print it.

Input: he knows malayalam

Output: he knows
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    char string[] = " 99 qqw";

    int i = 0;
    bool ispalindrome = true;
    int front,rear;

    while (string[i] != '\0')
    {
        front = rear = i;

        while (isalpha(string[rear]) != 0 && string[rear] != '\0') { rear++; }

        // check palindrome
        int j = front , k = rear - 1;
        while (j < k)
        {
            if (string[j] != string[k])
            {
                ispalindrome = false;
                break;
            }
            j++;
            k--;
        }

        // if not a palindrome print
        if (!ispalindrome)
        {
            for (int l = front; l < rear; l++)
            {
                printf("%c",string[l]);
            }

            printf(" ");
        }
        
        ispalindrome = true;
        i = rear;
        i++;
    }

    printf("\n");
    return 0;
}
