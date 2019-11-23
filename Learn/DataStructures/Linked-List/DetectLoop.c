#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *nextNode;
};

void printList(struct Node *node);
bool DetectLoopinList(struct Node *head);
long int LoopLength(struct Node *list);

int main(int argc, char const *argv[])
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *tail = (struct Node *)malloc(sizeof(struct Node));


    head->data = 1;
    head->nextNode = head;

    second->data = 2;
    second->nextNode = third;

    third->data = 3;
    third->nextNode = tail;

    tail->data = 4;
    tail->nextNode = second;

    // printList(head);
    printf("%s\n",(DetectLoopinList(head)) ? "Loop detected" : "No loop found");

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

// Floyd’s Cycle-Finding Algorithm
bool DetectLoopinList(struct Node *head)
{
    struct Node *slow_ptr = head, *fast_ptr = head;

    while (slow_ptr && fast_ptr && fast_ptr->nextNode)
    {
        slow_ptr = slow_ptr->nextNode; // Increment by 'One' step
        fast_ptr = fast_ptr->nextNode->nextNode; // Increment by 'Two' step

        if (slow_ptr == fast_ptr)
        {
            LoopLength(slow_ptr);
            return true;
        }
        
    }
    
    return false;
}

long int LoopLength(struct Node *node)
{
    long int length = 1;
    struct Node *node1 = node;
    
    while (node1->nextNode != node)
    {
        length++;
        node1 = node1->nextNode;
    }
    
    printf("Loop length : %ld\n",length);
    return length;
}