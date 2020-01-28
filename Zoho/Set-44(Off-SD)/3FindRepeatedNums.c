/*
Get the repeated numbers in the array
*/

#include<stdio.h>
#include<stdlib.h>

struct Number
{
    int number;
    int count;
    struct Number *next;
};

int main()
{
    int n = 8;
    int numbers[] = {1,2,3,1,3,6,6,66};

    struct Number *firstNumber = NULL;

    for (int i = 0; i < sizeof(numbers)/sizeof(int); i++)
    {
        if (firstNumber == NULL)
        {
            firstNumber = (struct Number *)malloc(sizeof(struct Number));
            firstNumber->number = numbers[i];
            firstNumber->count = 1;
            firstNumber->next = NULL;
        }
        else
        {
            struct Number *temp = firstNumber;

            while (temp != NULL)
            {
                if (temp->number == numbers[i])
                {
                    temp->count += 1;
                    temp = NULL;
                    break;
                }
                else if (temp->next == NULL)
                {
                    break; // No numbers matched so far.So append the new number
                }
                
                temp = temp->next;
            }

            if (temp) // Newnumber
            {
                struct Number *newNumber = (struct Number *)malloc(sizeof(struct Number));
                newNumber->number = numbers[i];
                newNumber->count = 1;
                newNumber->next = NULL;

                temp->next = newNumber;
            }
        }
    }

    struct Number *temp = firstNumber;

    while (temp != NULL)
    {
        if (temp->count > 1)
        {
            printf("%d ",temp->number);
        }
        temp = temp->next;
    }
    printf("\n");
    
    return 0;
}
