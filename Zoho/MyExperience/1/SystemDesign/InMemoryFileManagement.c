#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROOTDIRNAME "root"

struct DirNode
{
    char parentDirName[256];
    char dirname[256];
    int totalSubDirCount;
    int totalFileCount;

    struct DirNode *nextSibling; // Points first same level Directory (Sibling)
    struct DirNode *firstDir; // Points first sub-folder (Child)
    struct FileNode *firstFile; // Points the first FILE in the directory
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
struct FileNode *CreateNewFile(struct DirNode *rootNode,char parentDirName[],char newFileName[],char fileContent[]);

// Read
void printDirectories(struct DirNode *node,int n);
void printFiles(struct FileNode *fileNode,int n);


int main()
{
    struct DirNode *rootNode = CreateNewDir(NULL,NULL,ROOTDIRNAME,NULL);
    CreateNewDir(rootNode,ROOTDIRNAME,"F1",rootNode);
    CreateNewDir(rootNode,ROOTDIRNAME,"F2",rootNode);

    CreateNewDir(rootNode,"F1","F1.1",rootNode);
    CreateNewDir(rootNode,"F1","F1.2",rootNode);

    CreateNewDir(rootNode,"F1.1","F1.1.0",rootNode);
    CreateNewDir(rootNode,"F1.1","F1.1.1",rootNode);
    CreateNewDir(rootNode,"F1.1","F1.1.2",rootNode);

    CreateNewDir(rootNode,"F1.112","F1.1.2",rootNode); // Invalid parent dir

    // File Part
    CreateNewFile(rootNode,ROOTDIRNAME,"F1.txt","Content goes here");
    CreateNewFile(rootNode,ROOTDIRNAME,"F1.1.txt","Content goes here");
    CreateNewFile(rootNode,"F1.1.2","F1.1.2.1.txt","F1.1.2.1 Content goes here");
    CreateNewFile(rootNode,"F1.1.0","F1.1.0.1.txt","F1.1.0.1.txt Content goes here");
    CreateNewFile(rootNode,"F1.1.0","F1.1.0.2.txt","F1.1.0.2.txt Content goes here");
    CreateNewFile(rootNode,"F2","F2.1.txt","F2.1.txt Content goes here");
    

    printDirectories(rootNode,0);
    printf("\n");
    return 0;
}

struct DirNode *CreateNewDir(struct DirNode *rootNode,char parentDirName[],char newDirName[],struct DirNode *currentNode)
{
    if (rootNode == NULL)
    {
        struct DirNode *newRootNode = (struct DirNode *)malloc(sizeof(struct DirNode));
        newRootNode->nextSibling = NULL;
        newRootNode->firstDir = NULL;

        strcpy(newRootNode->dirname,newDirName);
        strcpy(newRootNode->parentDirName,"Root itself the parent dir");
        return newRootNode;
    }
    else if (currentNode != NULL && strcmp(parentDirName,currentNode->dirname) == 0)
    {
        struct DirNode *newNode = (struct DirNode *)malloc(sizeof(struct DirNode));
        newNode->nextSibling = NULL;
        newNode->firstDir = NULL;

        strcpy(newNode->parentDirName,parentDirName);
        strcpy(newNode->dirname,newDirName);

        if (currentNode->firstDir == NULL)
        {
            currentNode->firstDir = newNode;
        }
        else
        {
            struct DirNode *tempNode = currentNode->firstDir;

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
        if (currentNode == NULL) {
            return NULL;
        }
        
        CreateNewDir(rootNode,parentDirName,newDirName,currentNode->firstDir);
        return CreateNewDir(rootNode,parentDirName,newDirName,currentNode->nextSibling);
    }
}

struct FileNode *CreateNewFile(struct DirNode *node,char parentDirName[],char newFileName[],char fileContent[])
{
    if (node != NULL && strcmp(node->dirname,parentDirName) == 0)
    {
        struct FileNode *newFileNode = (struct FileNode *)malloc(sizeof(struct FileNode));
        newFileNode->nextSibling = NULL;

        strcpy(newFileNode->directParentDir,parentDirName);
        strcpy(newFileNode->fileName,newFileName);
        strcpy(newFileNode->fileContent,fileContent);

        if (node->firstFile != NULL)
        {
            struct FileNode *tempFilePtr = node->firstFile;

            while (tempFilePtr->nextSibling != NULL)
            {
                tempFilePtr = tempFilePtr->nextSibling;
            }
            
            tempFilePtr->nextSibling = newFileNode;
        }
        else
        {
            node->firstFile = newFileNode;
        }
        
        return newFileNode;
    }
    else
    {
        if (node == NULL)
        {
            return NULL;
        }
        
        CreateNewFile(node->firstDir,parentDirName,newFileName,fileContent);
        return CreateNewFile(node->nextSibling,parentDirName,newFileName,fileContent);
    }
}

void printDirectories(struct DirNode *node,int n)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        printf("%*c|--> %s\n ",n,' ',node->dirname);
        printDirectories(node->firstDir,n+1);
        printFiles(node->firstFile,n+1);
        printDirectories(node->nextSibling,n);
    }
}

void printFiles(struct FileNode *fileNode,int n)
{
    if (fileNode == NULL)
    {
        return;
    }
    else
    {
        printf("%*c|--> %s**\n ",n,' ',fileNode->fileName);
        printFiles(fileNode->nextSibling,n);
    }
}
