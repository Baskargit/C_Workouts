// https://practice.geeksforgeeks.org/problems/make-a-distinct-digit-array/0

#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    getchar();
    char numberstring[n*16];
    scanf("%[^\n]s",numberstring);

    // initialize with zeros
    int numcount[10];
    for (int i = 0; i < 10; i++)
    {
        numcount[i] = 0;
    }

    for (int i = 0; numberstring[i] != '\0'; i++)
    {
        numcount[numberstring[i] - '0'] += 1;
    }

    // Print result
    for (int i = 0; i < 10; i++)
    {
        if(numcount[i] > 0) {
            printf("%d ",i);
        }
    }
    printf("\n");
    
    return 0;
}
