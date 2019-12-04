/*
4.array of numbers were given to find a number which has same sum of numbers in it’s either side.

I/p 1, 2, 3, 7, 6

O/p 7(has 1+ 2+3 in left 6 in right)

*/

#include <stdio.h>

int main()
{
    unsigned long int n = 5;
    unsigned long int arr[] = {1,3,5,2,2};

    long int position = -1;

    for (long int i = 0; i < n; i++)
    {
        unsigned long int leftsum = 0,rightsum = 0;

        for (long int j = 0; j < i - 1; j++)
        {
            leftsum += arr[j];
        }

        for (long int j = i+1; j < n; j++)
        {
            rightsum += arr[j];
        }

        position = (leftsum == rightsum) ? i+1 :position;
    }

    printf("%ld",position);
    
    return 0;
}
