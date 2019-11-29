// https://www.geeksforgeeks.org/zoho-interview-experience-for-software-developer/
// Reverse the string without disturbing the vowels and space.

#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "aeiou12345";
    int strlength = strlen(s); 

    int leftptr = 0;
    int rightptr = strlength - 1;

    printf("%s\n",s);

    while (leftptr < rightptr)
    {
        while (s[leftptr] == 'a' || s[leftptr] == 'e' || s[leftptr] == 'i' || s[leftptr] == 'o' || s[leftptr] == 'u' || s[leftptr] == ' ') 
        {
            ++leftptr;        
        }

        while (s[rightptr] == 'a' || s[rightptr] == 'e' || s[rightptr] == 'i' || s[rightptr] == 'o' || s[rightptr] == 'u' || s[leftptr] == ' ') 
        {
            --rightptr;        
        }

        if (leftptr != rightptr) {
            char temp = s[leftptr];
            s[leftptr] = s[rightptr];
            s[rightptr] = temp;
        }

        ++leftptr;
        --rightptr;
    }

    printf("%s\n",s);
    return 0;
}