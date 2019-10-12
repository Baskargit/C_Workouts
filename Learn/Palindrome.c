#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int testCaseCount;
    printf("Total TestCase count :\n");
    scanf("%d",&testCaseCount);

    for (int i = 0; i < testCaseCount; i++)
    {
        printf("\nEnter a number to check whether it is Palindrome or not\n");

        char number[255];
        bool isPalindrome = true;

        scanf("%s",number);
        int length = strlen(number);

        if(length % 2 != 0)  // Odd
        {
            for (int i = 0,j = length - 1; i < (length / 2) && j > 0; i++,j--)
            {
                if (*(number + i) != *(number + j))
                {
                    isPalindrome = false;
                    break;
                }
                
            }
        } else // Even
        {
            for (int i = 0,j = length - 1; i <= (length / 2) - 1; i++,j--)
            {
                if (*(number + i) != *(number + j))
                {
                    isPalindrome = false;
                    break;
                }
                
            }
        }

        printf("%s\n",(isPalindrome) ? "Palindrome" : "Not a Palindrome");
    
    }

    return 0;
}
