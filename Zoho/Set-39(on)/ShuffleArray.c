/*
9. Shuffle an Array
Given a range of numbers print the numbers such that they are shuffled
First line contains no. of test cases.
I/P:
3
1 10
5 12
1 10

O/P: (The order of numbers may vary)
2 3 9 5 1 10 6 7 8 4
5 6 9 12 10 11 7 8
9 5 1 2 3 4 8 7 6 10

If any of the given ranges are same, The orders of the numbers must vary.
I/P: 4
1 7
1 7
1 7
1 7
O/P:
6 7 1 5 2 3 4
1 7 2 6 3 5 4
6 3 5 1 4 2 7
1 2 3 6 5 7 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int t;
    scanf("%d",&t);

    while (t-- > 0)
    {
        srand(time(NULL));

        int minrange = 1;
        int maxrange = 10;
        scanf("%d %d",&minrange,&maxrange);

        int numbers[maxrange - minrange];
        int counter = 0;

        for (int i = minrange; i <= maxrange; i++)
        {
            numbers[counter++] = i;
        }

        for (int i = counter - 1; i > 0; i--)
        {
            int j = rand() % (i + 1);

            int temp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
        }

        for (int i = 0; i < counter; i++)
        {
            printf("%d ",numbers[i]);
        } 
        
        printf("\n");
    }
    
    return 0;
}
