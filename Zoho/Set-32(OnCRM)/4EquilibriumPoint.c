/*
4.array of numbers were given to find a number which has same sum of numbers in it’s either side.

I/p 1, 2, 3, 7, 6

O/p 7(has 1+ 2+3 in left 6 in right)

*/

// Below solution is inefficient
// Time complexity of this solution is O(n^2).
// #include <stdio.h>

// int main()
// {
//     unsigned long int n = 1;
//     unsigned long int arr[] = {1};

//     long int position = -1;

//     for (long int i = 0; i < n; i++)
//     {
//         unsigned long int leftsum = 0,rightsum = 0;

//         for (long int j = 0; j < i; j++)
//         {
//             leftsum += arr[j];
//         }

//         for (long int j = i+1; j < n; j++)
//         {
//             rightsum += arr[j];
//         }

//         if(leftsum == rightsum) {
//             position = i+1;
//             break;
//         }
//     }

//     printf("%ld\n",position);
    
//     return 0;
// }

// Efficient solution

#include <stdio.h>

int main()
{
    unsigned long int n = 5;
    unsigned long int arr[] = {1,3,5,2,2};

    long int position = -1;
    unsigned long int sum = 0;
    for (long int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    unsigned long int leftsum = 0,rightsum = 0;
    rightsum = sum;

    for (long int i = 0; i < n; i++)
    {
        rightsum -= arr[i];

        if(leftsum == rightsum) {
            position = i+1;
            break;
        }

        leftsum += arr[i];
    }

    printf("%ld\n",position);
    
    return 0;
}