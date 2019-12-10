#include <stdio.h>
#include <string.h>

int permutationscount(int length);

int main()
{
    char str[] = "ABCDA";
    int sample = 3;
    int length = strlen(str);

    int permcount = permutationscount(length);

    char permuations[permcount][length];

    

    return 0;
}

int permutationscount(int length)
{
    int count = length;

    while (--length >=1 && (count *= length));

    return count;
}
