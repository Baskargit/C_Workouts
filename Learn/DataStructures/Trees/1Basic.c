#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *leftchild;
    struct node *rightchild;
};

struct node * insert(struct node *node,int value);
void inordertraverse(struct node *node);

int main()
{
    
    struct node *root = insert(NULL,3);
    insert(root,1);
    insert(root,4);
    insert(root,5);
    insert(root,4);
    insert(root,2);
    insert(root,0);

    inordertraverse(root);
    printf("\n");

    return 0;
}

struct node * insert(struct node *node,int value)
{
    if (node == NULL)
    {
        struct node *rootNode = (struct node *)malloc(sizeof(struct node));
        rootNode->data = value;
        rootNode->leftchild = NULL;
        rootNode->rightchild = NULL;

        return rootNode;
    }

    if (value <= node->data)
    {
        if (node->leftchild == NULL)
        {
            struct node *newLeftChild = (struct node *)malloc(sizeof(struct node));
            newLeftChild->data = value;
            newLeftChild->leftchild = NULL;
            newLeftChild->rightchild = NULL;

            node->leftchild = newLeftChild;
            return newLeftChild;
        }
        else
        {
            insert(node->leftchild,value);
        }
    }
    else
    {
        if (node->rightchild == NULL)
        {
            struct node *newRightChild = (struct node *)malloc(sizeof(struct node));
            newRightChild->data = value;
            newRightChild->leftchild = NULL;
            newRightChild->rightchild = NULL;

            node->rightchild = newRightChild;
            return newRightChild;
        }
        else
        {
            insert(node->rightchild,value);
        }
    }
}

void inordertraverse(struct node *node)
{
    if (node == NULL)
    {
        return;
    }

    inordertraverse(node->leftchild);

    printf("%d ",node->data);

    inordertraverse(node->rightchild);
    
}
