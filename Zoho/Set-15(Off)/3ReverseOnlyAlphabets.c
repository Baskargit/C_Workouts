#include <stdio.h>
#include <string.h>

int main()
{
    char string[] = "dakA&*hA@#N";
    int length = strlen(string);

    int front = 0 , last = length - 1;

    while (front < last && last > front)
    {
        while (!(string[front] >= 'a' && string[front] <= 'z' || string[front] >= 'A' && string[front] <= 'Z') && front < last)
        {
            front++;
        }

        while (!(string[last] >= 'a' && string[last] <= 'z' || string[last] >= 'A' && string[last] <= 'Z') && last > front)
        {
            last--;
        }

        char temp = string[last];
        string[last] = string[front];
        string[front] = temp;

        front++;
        last--;
    }

    printf("%s\n",string);
    

    return 0;
}
