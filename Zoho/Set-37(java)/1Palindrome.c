/*
1.Given a String with or without special characters find if it is Palindrome or Not.. 
No splitting of array must be done or No additional spaces must be used for storing the array..

Eg: RACE CAR => No

Eg: I DID, DID I ? => Yes
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    char input[] = "   &&(&(&*7I DID, DID I ?9989979789";

    int length = strlen(input);

    int leftptr = 0;
    int rightptr = length - 1;
    bool ispalindrome = true;

    while ((leftptr < rightptr && rightptr != leftptr) && ispalindrome)
    {
        while (isalpha(input[leftptr]) == 0) { ++leftptr; }
        
        while (isalpha(input[rightptr]) == 0) { --rightptr; }

        if (input[leftptr] != input[rightptr])
        {
            ispalindrome = false;
        }
        leftptr++;
        rightptr--;
    }

    printf("%s\n",(ispalindrome) ? "Yes" : "No");
    

    return 0;
}
