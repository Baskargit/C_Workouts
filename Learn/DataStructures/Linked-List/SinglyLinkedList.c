#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *nextNode;
};

// =========> Create ===========>
void InsertAtFront(struct Node **head,struct Node *newHeadNode);
void InsertAtEnd(struct Node *head,struct Node *newTailNode);
void InsertAtN(struct Node *previousNode,struct Node *newNthNode);

// ============> Read ===============>
void printList(struct Node *node);

// ==============> Update ===============>

// ================> Delete ================>
void DeleteNode(struct Node **head,int key); // by key
void DeleteNode(struct Node **head,int position); // by position
void DeleteList(struct Node **head);

// =============> List utilities <===========
long int ListCount(struct Node *head);


int main()
{
    printf("Size of Node is = %ld\n\n",sizeof(struct Node));

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->nextNode = second;

    second->data = 2;
    second->nextNode = third;

    third->data = 4;
    third->nextNode = NULL;

    printList(head);

    // ==============================> Create a Node <==========================
    printf("Insert at front\n");
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = 0;
    InsertAtFront(&head,newNode);
    printList(head);

    printf("Insert at N\n");
    struct Node *newNthNode = (struct Node *)malloc(sizeof(struct Node));
    newNthNode->data = 3;
    InsertAtN(second,newNthNode);
    printList(head);

    printf("Insert at End\n");
    struct Node *newTailNode = (struct Node *)malloc(sizeof(struct Node));
    newTailNode->data = 5;
    InsertAtEnd(head,newTailNode);
    printList(head);

    printf("\nList length = %ld",ListCount(head));

    // ==============================> Delete a Node <==========================
    printf("\n\nDelete 'Nth' node\n");
    DeleteNode(&head,4);
    printList(head);

    printf("Delete 'HEAD' node\n");
    DeleteNode(&head,0);
    printList(head);

    printf("Delete 'TAIL' node\n");
    DeleteNode(&head,5);
    printList(head);

    printf("\nList length = %ld",ListCount(head));

    printf("\n\nDelete 'List'\n");
    DeleteList(&head);
    printList(head);

    printf("List length = %ld\n",ListCount(head));

    return 0;
}

void printList(struct Node *node)
{
    for (;node != NULL;node = node->nextNode)
    {
        printf("%d ",node->data);
    }
    printf("\n");
}

// ===========================> Create <==================================
void InsertAtFront(struct Node **head,struct Node *newHeadNode)
{
    newHeadNode->nextNode = *head;
    (*head) = newHeadNode;
}

void InsertAtEnd(struct Node *head,struct Node *newTailNode)
{
    if (head == NULL || newTailNode == NULL)
    {
        return;
    }
    
    struct Node *node;
    node = head;

    while (1)
    {
        if (node->nextNode == NULL) {
            node->nextNode = newTailNode;
            newTailNode->nextNode = NULL;
            break;
        }

        node = node->nextNode;
    }
    
}

void InsertAtN(struct Node *previousNode,struct Node *newNthNode)
{
    if (previousNode != NULL)
    {
        newNthNode->nextNode = previousNode->nextNode;
        previousNode->nextNode = newNthNode;   
    }
}

// =====================================> Delete (only first occurence)<=========================================

void DeleteNode(struct Node **head,int key)
{
    struct Node *node;
    node = *head;

    // 1.If it is a HEAD node
    if (node->data == key)
    {
        (*head) = node->nextNode;
        free(node);
        return;
    }

    while (node != NULL)
    {
        if (node->nextNode->data == key) {
            // 2.If it is Nth Node
            if (node->nextNode->nextNode != NULL)
            {
                struct Node *matchedNode = node->nextNode;

                node->nextNode = matchedNode->nextNode;
                free(matchedNode);
                return;
            }

            // 3.If it is a TAIL node
            free(node->nextNode);
            node->nextNode = NULL;
            return;
        }
        node = node->nextNode;
    }  
}

void DeleteList(struct Node **head)
{
    struct Node *node = *head, *nextNode;

    while (node != NULL)
    {
        nextNode = node->nextNode;
        free(node);
        node = nextNode;
    }
    
    (*head) = NULL;
}

// ==================================> List Utilities <====================================

long int ListCount(struct Node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    return 1 + ListCount(head->nextNode);
}
