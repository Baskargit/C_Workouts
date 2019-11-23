#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int position;
    struct Node *nextPosition;
};

void deleteNode(struct Node **head,struct Node *currentNode,struct Node *toBeDeleted);
void pushNode(struct Node **head,int position);
void displayList(struct Node *node);
int getSurvivor(struct Node **head,int m);

int main()
{
    int n = 41,m = 40;

    struct Node *head = NULL;

    for (int i = 1; i <= n; i++)
    {
        pushNode(&head,i);
    }

    displayList(head);
    printf("%d\n",getSurvivor(&head,m));
    
    return 0;
}

int getSurvivor(struct Node **head,int m)
{
    if (m == 1)
    {
        int counter = 0;

        struct Node *temp = *head;

        while (temp->nextPosition != *head)
        {
            counter++;
            temp = temp->nextPosition;
        }
        
        return counter + 1;
    }
    
    int count = 1;
    int skip = ((m-1) > 1) ? m-1 : 1;

    struct Node *temp = *head;
    struct Node *previousNode;

    while (temp->nextPosition != temp)
    {
        if (count > skip)
        {
            deleteNode(head,previousNode,temp);
            count = 1;
            temp = temp->nextPosition;
        }

        count++;
        previousNode = temp;
        temp = temp->nextPosition;
    }

    return temp->position;
}

void deleteNode(struct Node **head,struct Node *currentNode,struct Node *toBeDeleted)
{
    if (toBeDeleted != *head && toBeDeleted->nextPosition != *head)
    {
        currentNode->nextPosition = toBeDeleted->nextPosition;
        free(toBeDeleted);
    } else if(toBeDeleted == *head) {
        currentNode->nextPosition = toBeDeleted->nextPosition;
        free(toBeDeleted);
        *head = currentNode->nextPosition;
    } else {
        currentNode->nextPosition = *head;
        free(toBeDeleted);
    }
}

void displayList(struct Node *head)
{
    struct Node *temp = head;

    if (head != NULL)
    {
        do
        {
            printf("%d ",temp->position);
            temp = temp->nextPosition;
        } while (temp != head);
    }
    
    printf("\n");
    
}

void pushNode(struct Node **head,int position)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->position = position;

    if (head != NULL && *head != NULL )
    {
        struct Node *temp = *head;

        while (temp->nextPosition != *head)
        {
            temp = temp->nextPosition;
        }

        temp->nextPosition = newNode;
        newNode->nextPosition = *head;
        return;
    }

    newNode->nextPosition = newNode;
    *head = newNode;
}