/*
5. Insert 0 after consecutive (K times) of 1 is found.
Example:

Input:
Number of bits: 12
Bits: 1 0 1 1 0 1 1 0 1 1 1 1
Consecutive K: 2

12
2
1 0 1 1 0 1 1 0 1 1 1 1

Output:
1 0 1 1 0 0 1 1 0 0 1 1 0 1 1 0
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int num;
    struct Node *next;
};

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->next = NULL;
    struct Node *previousnode = head;

    int temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&temp);

        if(i) {
            struct Node *node = (struct Node *)malloc(sizeof(struct Node));
            node->num = temp;
            node->next = NULL;

            previousnode->next = node;
            previousnode = node;
        } else {
            head->num = temp;
        }
    }

    struct Node *node = head;
    int count = 0; 
    while (node != NULL)
    {
        count = (node->num == 0) ? 0 : count + 1;

        if(count == k) {
            struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
            newnode->num = 0;
            newnode->next = (node->next == NULL) ? NULL : node->next;

            node->next = newnode;
        }

        node = node->next;
    }

    node = head;
    while (node != NULL)
    {
        printf("%d ",node->num);
        node = node->next;
    }

    
    printf("\n");
    return 0;
}
