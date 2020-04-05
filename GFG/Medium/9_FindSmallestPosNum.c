// https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number/0

#include<stdio.h>
#include<stdlib.h>

struct PosNum
{
    unsigned int num;
    struct PosNum *next;
};

void insertPosNum(unsigned int number,struct PosNum **start);
void printPosNumbers(struct PosNum *start);
unsigned int getMinimumPos(struct PosNum *start);

int main()
{
    unsigned int n;
    scanf("%d",&n);

    int array[n],firstMinPos = 0,flag = 1;
    struct PosNum *start = NULL;

    for (unsigned int i = 0; i < n; i++)
    {
        scanf("%d",&array[i]);

        if (flag && array[i] >= 0)
        {
            flag = 0;
            
            start = (struct PosNum *)malloc(sizeof(struct PosNum));
            start->num = array[i];
            start->next = NULL;
        }
        else
        {
            if (array[i] >= 0)
            {
                insertPosNum(array[i],&start);
            }
        }
    }

    printPosNumbers(start);

    firstMinPos = getMinimumPos(start);
    printf("%d\n",firstMinPos);
    return 0;
}

unsigned int getMinimumPos(struct PosNum *start)
{
    if (start->num > 1)
    {
        return 1;
    }
    else
    {
        while (start)
        {
            if (start->next != NULL)
            {
                if (!(start->num + 1 == start->next->num || start->num == start->next->num))
                {
                    return start->num + 1;
                }
            }
            else
            {
                return start->num + 1;
            }
            start = start->next;
        }
    }
}

void insertPosNum(unsigned int number,struct PosNum **start)
{
    struct PosNum *temp = *start;
    struct PosNum *newNumber = (struct PosNum *)malloc(sizeof(struct PosNum));
    newNumber->num = number;
    newNumber->next = NULL;

    if (number < (*start)->num)
    {
        newNumber->next = *start;
        *start = newNumber;
        return;
    }
    else
    {
        if (temp->next != NULL)
        {
            while (temp != NULL)
            {
                if (number >= temp->num)
                {
                    if (temp->next != NULL && number <= temp->next->num)
                    {
                        newNumber->next = temp->next;
                        temp->next = newNumber;
                        break;
                    }
                    else
                    {
                        if (temp->next == NULL)
                        {
                            temp->next = newNumber;
                            break;
                        }
                    }
                }
                
                temp = temp->next;
            }
        }
        else
        {
            (*start)->next = newNumber;
        }
    }
}

void printPosNumbers(struct PosNum *start)
{
    printf("Linked Postive numbers :\n");
    while (start)
    {
        printf("%d ",start->num);
        start = start->next;
    }
    printf("\n");
}



/*

Input:
22
8 45 -21 -13 -15 43 -32 -22 -7 -39 -22 -21 26 -46 -7 13 -37 -12 -44 -10 -46 -32

Its Correct output is:
1

And Your Code's output is:
9

Input:
85
-47 1 4 49 -18 10 26 18 -11 -38 -24 36 44 -11 45 20 -16 28 17 -49 47 -48 -33 42 2 6 -49 30 36 -9 15 39 -6 -31 -10 -21 -19 -33 47 21 31 25 -41 -23 17 6 47 3 36 15 -44 33 -31 -26 -22 21 -18 -21 -47 -31 20 18 -42 -35 -10 -1 46 -27 -32 -5 -4 1 -29 5 29 38 14 -22 -9 0 43 -50 -16 14 -26

Its Correct output is:
7

And Your Code's output is:
-46

*/
