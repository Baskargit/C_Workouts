#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

struct BstNode* insert(struct BstNode *bstNode,int data);
bool search(struct BstNode *bstNode,int key);

void inordertraversel(struct BstNode *bstNode);

int main()
{
    struct BstNode *rootNode = insert(NULL,3);
    insert(rootNode,1);
    insert(rootNode,4);
    insert(rootNode,0);

    insert(rootNode,2);
    insert(rootNode,4);
    insert(rootNode,5);

    inordertraversel(rootNode); // Inorder traversal
    printf("\n");

    int keytosearch = 50;
    printf("Key %d %s in the tree\n",keytosearch,(search(rootNode,keytosearch)) ? "exists" : "not exists");
    return 0;
}

struct BstNode* insert(struct BstNode *bstNode,int data)
{
    if (bstNode == NULL) // Create new BSTNode
    {
        bstNode = (struct BstNode *)malloc(sizeof(struct BstNode));
        bstNode->data = data;
        bstNode->left = bstNode->right = NULL;
    }
    else if(data <= bstNode->data)
    {
        bstNode->left = insert(bstNode->left,data);
    }
    else
    {
        bstNode->right = insert(bstNode->right,data);
    }
    
    return bstNode;
}

bool search(struct BstNode *bstNode,int key)
{
    if (bstNode == NULL)
    {
        return false;
    }
    else if (key == bstNode->data)
    {
        return true;
    }
    else if (key <= bstNode->data)
    {
        return search(bstNode->left,key);
    }
    else
    {
        return search(bstNode->right,key);
    }
    
}

void inordertraversel(struct BstNode *bstNode)
{
    // printf("Accessing Node : %d\n",(bstNode != NULL) ? bstNode->data : -111);

    if (bstNode == NULL)
    {
        return;
    }
    
    inordertraversel(bstNode->left);
    printf("%d ",bstNode->data);
    inordertraversel(bstNode->right);
}