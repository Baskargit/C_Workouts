#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROOTDIRNAME "root"

struct DirNode
{
    char parentDirName[256];
    char dirname[256];

    struct DirNode *nextSibling; // Points same level dir node (siblings)
    struct DirNode *firstChild; // Points sub-folders
};

struct FileNode
{
    char directParentDir[256];
    char fileName[256];
    char fileContent[2048];

    struct FileNode *nextSibling;
};

// Create
struct DirNode *CreateNewDir(struct DirNode *rootNode,char parentDirName[],char newDirName[],struct DirNode *currentNode);

// Read
void printDirectories(struct DirNode *rootNode);


int main()
{
    struct DirNode *rootNode = CreateNewDir(NULL,NULL,ROOTDIRNAME,NULL);
    CreateNewDir(rootNode,ROOTDIRNAME,"F1",rootNode);
    CreateNewDir(rootNode,ROOTDIRNAME,"F2",rootNode);

    CreateNewDir(rootNode,"F1","F1.1",rootNode);
    CreateNewDir(rootNode,"F1","F1.2",rootNode);

    printDirectories(rootNode);
    return 0;
}

struct DirNode *CreateNewDir(struct DirNode *rootNode,char parentDirName[],char newDirName[],struct DirNode *currentNode)
{
    if (rootNode == NULL)
    {
        struct DirNode *newRootNode = (struct DirNode *)malloc(sizeof(struct DirNode));
        newRootNode->nextSibling = NULL;
        newRootNode->firstChild = NULL;

        strcpy(newRootNode->dirname,newDirName);
        strcpy(newRootNode->parentDirName,"Root itself the parent dir");
        return newRootNode;
    }
    else if (strcmp(parentDirName,currentNode->dirname) == 0)
    {
        struct DirNode *newNode = (struct DirNode *)malloc(sizeof(struct DirNode));
        newNode->nextSibling = NULL;
        newNode->firstChild = NULL;

        strcpy(newNode->parentDirName,parentDirName);
        strcpy(newNode->dirname,newDirName);

        if (currentNode->firstChild == NULL)
        {
            currentNode->firstChild = newNode;
        }
        else
        {
            struct DirNode *tempNode = currentNode->firstChild;

            while (tempNode->nextSibling != NULL) // traverse untill the last same level sibling
            {
                tempNode = tempNode->nextSibling;
            }

            tempNode->nextSibling = newNode; // attach the newNode with the last sibling
        }

        return newNode;
    }
    else
    {
        if (currentNode == NULL)
        {
            return NULL;
        }
        
        CreateNewDir(rootNode,parentDirName,newDirName,currentNode->firstChild);
        return CreateNewDir(rootNode,parentDirName,newDirName,currentNode->nextSibling);
    }
}

void printDirectories(struct DirNode *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        printf("%s\n",node->dirname);
        printDirectories(node->firstChild);
        // printf("|\n");
        // printf("--- ");
        printDirectories(node->nextSibling);
    }
}
