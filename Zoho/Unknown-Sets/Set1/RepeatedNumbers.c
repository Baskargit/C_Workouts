// Get the repeated numbers in the array
// // https://www.geeksforgeeks.org/zoho-interview-experience-for-software-developer/

#include <stdio.h>

int main()
{
    int array[] = {1,2,5,3,4,6,2,3,1};
    int size = sizeof(array)/sizeof(int);

    int repatedNumbers[size];
    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (array[i] == array[j])
            {
                repatedNumbers[counter++] = array[i];
                break;
            }
        }
        
    }

    for (int i = 0; i < counter; i++)
    {
        printf("%d ",repatedNumbers[i]);
    }

    printf("\n");
    return 0;
}
