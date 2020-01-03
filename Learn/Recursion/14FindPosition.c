/*
https://practice.geeksforgeeks.org/problems/finding-position/0

*/

#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int position;
    struct Queue *next;
};

struct Queue * initializeQueue(int n);

int main()
{
    unsigned int n;
    scanf("%d",&n);

    struct Queue *head = initializeQueue(n);
    int queuecount = n,currentPosition;

    while (queuecount > 1)
    {
        currentPosition = 1;
        struct Queue *current = head;
        struct Queue *previous = head;

        while (current != NULL)
        {
            if (currentPosition % 2 == 1)
            {
                if (current == head)
                {
                    head = (current->next != NULL) ? current->next : head;
                    --queuecount;
                }
                else
                {
                    previous->next = current->next;
                }
            }
            
            currentPosition++;
            previous = current;
            current = current->next;
        }
        
    }
    
    printf("%d\n",head->position);
    return 0;
}

struct Queue * initializeQueue(int n)
{
    struct Queue *head = (struct Queue *)malloc(sizeof(struct Queue));
    head->position = 1;
    head->next = NULL;

    struct Queue *previous = head;
    for (int i = 2; i <= n; i++)
    {
        struct Queue *newPos = (struct Queue *)malloc(sizeof(struct Queue));
        previous->next = newPos;

        newPos->position = i;
        newPos->next = NULL;

        previous = newPos;
    }
    
    return head;
}
