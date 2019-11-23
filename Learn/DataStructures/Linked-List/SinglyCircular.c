#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void PrintCircularList(struct Node *node);
void AddItemToList(struct Node **head,int data);
void DeleteNode(struct Node **head,int key);

void Reverse(struct Node **head);
void sortedInsert(struct Node** head_ref, int x);

int main()
{
    struct Node *n1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n4 = (struct Node *)malloc(sizeof(struct Node));

    n1->data = 2;
    n1->next = n2;

    n2->data = 3;
    n2->next = n1;

    n3->data = 3;
    n3->next = n4;

    n4->data = 4;
    n4->next = n1;

    PrintCircularList(n1);

    printf("\nAdd a new item \n");
    AddItemToList(&n1,5);
    PrintCircularList(n1);

    // printf("\nDelete an item \n");
    // DeleteNode(&n1,1);
    // PrintCircularList(n1);

    // printf("\nReverse list \n");
    // Reverse(&n1);
    // PrintCircularList(n1);
    // Reverse(&n1);
    // PrintCircularList(n1);

    sortedInsert(&n1,1);
    PrintCircularList(n1);

    return 0;
}

void sortedInsert(struct Node** head_ref, int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
        
   if(head_ref != NULL && *head_ref != NULL) 
   {
       
       if(x <= (*head_ref)->data) {
           newNode->next = *head_ref;

           struct Node *temp = *head_ref;

           while (temp->next != *head_ref)
           {
               temp = temp->next;
           }
           
           temp->next = newNode;
           *head_ref = newNode;
           return;
       } else if((*head_ref)->next == *head_ref) {
           (*head_ref)->next = newNode;
           newNode->next = *head_ref;
           return;
       }
       
       struct Node *temp = *head_ref;
       struct Node *previous = *head_ref;
       
       do {
           if(x >= temp->data && x <= temp->next->data)
           {
               newNode->next = temp->next;
               temp->next = newNode;
               return;
           }
           
           previous = temp;
           temp = temp->next;
           
       } while(temp != *head_ref);
       
       if(temp == *head_ref) {
            previous->next = newNode;
            newNode->next = *head_ref;   
       }
       
       return;
   }
   
   newNode->next = newNode;
   *head_ref = newNode;
}

void Reverse(struct Node **head)
{
    struct Node *previousNode = NULL;
    struct Node *currentNode = *head;
    struct Node *nextNode = *head;

    if (head != NULL && *head != NULL)
    {
        previousNode = *head;
        currentNode = currentNode->next;

        while (currentNode != *head)
        {
            nextNode = currentNode->next;
            currentNode->next = previousNode;

            previousNode = currentNode;
            currentNode = nextNode;    
        }

        currentNode->next = previousNode;

        *head = previousNode;
    }
    
}

void DeleteNode(struct Node **head,int key)
{
    if (head != NULL && *head != NULL)
    {
        struct Node *temp = *head;

        // If 'HEAD' node
        if ((*head)->data == key)
        {
            while (temp->next != *head)
            {
                temp = temp->next;
            }

            temp->next = (*head)->next;
            free(*head);
            *head = temp->next;
        } else
        {
            while (temp->next->data != key)
            {
                temp = temp->next;

                // If invalid key provided
                if (temp == *head)
                {
                    return;
                }
            }

            if (temp->next->next != *head)
            {
                // If node is not a 'TAIL' node
                struct Node *temp1 = temp->next->next;
                free(temp->next);
                temp->next = temp1;
            } else
            {
                // If 'TAIL' node
                free(temp->next);
                temp->next = *head;
            }
        }
    }
}

void AddItemToList(struct Node **head,int data)
{
    struct Node *newItem = (struct Node *)malloc(sizeof(struct Node));
    newItem->data = data;

    if (head != NULL)
    {
        struct Node *temp = *head;

        while (temp->next != *head){
            temp = temp->next;
        }
        
        temp->next = newItem;
        newItem->next = *head;
    } else {
        newItem->next = newItem;
        *head = newItem;
    }
}

void PrintCircularList(struct Node *node)
{
    struct Node *temp = node;

    if (temp != NULL)
    {
        do
        {
            printf("%d ",temp->data);
            temp = temp->next;
        } while (temp != node);
    }
    
    printf("\n");
}
