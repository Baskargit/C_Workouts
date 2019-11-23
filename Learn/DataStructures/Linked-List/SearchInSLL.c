// Search in Singly LinkedList

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *nextNode;
};

void printList(struct Node *node);
bool SearchInSLL(struct Node *head ,int key);

int main(int argc, char const *argv[])
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *tail = (struct Node *)malloc(sizeof(struct Node));


    head->data = 1;
    head->nextNode = second;

    second->data = 2;
    second->nextNode = third;

    third->data = 3;
    third->nextNode = tail;

    tail->data = 4;
    tail->nextNode = NULL;

    printList(head);

    printf("%s\n",(SearchInSLL(head,1000)) ? "Found" : "Not found");

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

bool SearchInSLL(struct Node *node ,int key)
{
    if (node->data == key)
    {
        return true;
    }
    else if (node->nextNode == NULL) {
        return false;
    }
    
    return SearchInSLL(node->nextNode,key);
}
