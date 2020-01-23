#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
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

    struct DirNode *parentDirNode; // Points it's direct parent
};

struct FileNode
{
    char directParentDir[256];
    char fileName[256];
    char fileContent[2048];

    struct FileNode *nextSibling;
    struct DirNode *parentDirNode;
};

// Create
struct DirNode *CreateNewDir(struct DirNode *rootNode,char parentDirName[],char newDirName[],struct DirNode *currentNode);
struct FileNode *CreateNewFile(struct DirNode *rootNode,char parentDirName[],char newFileName[],char fileContent[]);

// Read
void printDirectories(struct DirNode *node,int n);
void printFiles(struct FileNode *fileNode,int n);

// Update
bool UpdateDirName(struct DirNode *node,char oldDirName[],char newDirName[]);
bool UpdateFileName(struct DirNode *node,char oldFileName[],char newFileName[]);

// Delete
bool DeleteDir(struct DirNode *node,char dirName[]);
bool DeleteFile(struct DirNode *node,char fileName[]);

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

    // Update
    printf("\nAfter some updates\n\n");
    UpdateDirName(rootNode,"F2","F2 changed");
    UpdateDirName(rootNode,ROOTDIRNAME,"F2 changed");
    UpdateDirName(rootNode,"F1.1.2","F1.1.2 changed");

    UpdateFileName(rootNode,"F1.txt","F1-changed.txt");
    UpdateFileName(rootNode,"F1.1.0.2.txt","F1.1.0.2-changed.txt");

    printDirectories(rootNode,0);

    // Delete
    printf("\nAfter some Deletes\n\n");
    DeleteDir(rootNode,"F2 changed");
    // DeleteDir(rootNode,"F1");
    // DeleteDir(rootNode,"F1.1.0");
    DeleteDir(rootNode,"F1.1.2 changed");
    DeleteDir(rootNode,ROOTDIRNAME);

    DeleteFile(rootNode,"F1.1.0.2-changed.txt");
    // DeleteFile(rootNode,"F1.1.0.1.txt");

    printDirectories(rootNode,0);
    printf("\n");
    return 0;
}

// Create
struct DirNode *CreateNewDir(struct DirNode *rootNode,char parentDirName[],char newDirName[],struct DirNode *currentNode)
{
    if (rootNode == NULL)
    {
        struct DirNode *newRootNode = (struct DirNode *)malloc(sizeof(struct DirNode));
        newRootNode->nextSibling = NULL;
        newRootNode->firstDir = NULL;

        strcpy(newRootNode->dirname,newDirName);
        strcpy(newRootNode->parentDirName,"Root itself the parent dir");
        newRootNode->parentDirNode = newRootNode;
        return newRootNode;
    }
    else if (currentNode != NULL && strcmp(parentDirName,currentNode->dirname) == 0)
    {
        struct DirNode *newNode = (struct DirNode *)malloc(sizeof(struct DirNode));
        newNode->nextSibling = NULL;
        newNode->firstDir = NULL;
        newNode->parentDirNode = currentNode;

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
        newFileNode->parentDirNode = node;

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

// Update
bool UpdateDirName(struct DirNode *node,char oldDirName[],char newDirName[])
{
    if (node != NULL && strcmp(node->dirname,oldDirName) == 0)
    {
        if (strcmp(node->dirname,ROOTDIRNAME)) // Exclude root dir
        {
            strcpy(node->dirname,newDirName);
            printf("Directory \"%s\" had been changed to \"%s\"\n",oldDirName,newDirName);
            return true;
        }
        else
        {
            printf("Root name cannot be changed!!\n");
            return false;
        }
    }
    else if (node == NULL)
    {
        return false;
    }

    return (UpdateDirName(node->firstDir,oldDirName,newDirName)) ? true : UpdateDirName(node->nextSibling,oldDirName,newDirName);
}

bool UpdateFileName(struct DirNode *node,char oldFileName[],char newFileName[])
{
    if (node != NULL && node->firstFile != NULL)
    {
        struct FileNode *fileNode = node->firstFile;

        while (fileNode)
        {
            if (strcmp(fileNode->fileName,oldFileName) == 0)
            {
                strcpy(fileNode->fileName,newFileName);
                printf("File \"%s\" had been changed to \"%s\"\n",oldFileName,newFileName);
                return true;
            }
            fileNode = fileNode->nextSibling;
        }
    }
    else if(node == NULL)
    {
        return false;
    }

    return (UpdateFileName(node->firstDir,oldFileName,newFileName)) ? true : UpdateFileName(node->nextSibling,oldFileName,newFileName);
}

// Delete
bool DeleteDir(struct DirNode *node,char dirName[])
{
    if (node != NULL && strcmp(node->dirname,dirName) == 0)
    {
        if (node->parentDirNode == node) // If it is a root node
        {
            printf("Root cannot be deleted\n");
            return false;
        }
        else if (node->parentDirNode->firstDir != node) // If the node is not the first child of its direct parent
        {
            struct DirNode *temp = node->parentDirNode->firstDir;

            while (temp->nextSibling != node)
            {
                temp = temp->nextSibling;
            }

            temp->nextSibling = node->nextSibling;
        }
        else
        {
            node->parentDirNode->firstDir = node->nextSibling;
        }

        printf("Directory \"%s\" had been successfully deleted\n",dirName);
        free(node);
        return true;
    }
    else if (node == NULL)
    {
        return false;
    }

    return (DeleteDir(node->firstDir,dirName)) ? true : DeleteDir(node->nextSibling,dirName);
}

bool DeleteFile(struct DirNode *node,char fileName[])
{
    if (node != NULL && node->firstFile != NULL)
    {
        struct FileNode *temp = node->firstFile;

        if (strcmp(node->firstFile->fileName,fileName) == 0) // If it is a firstFile for that node
        {
            node->firstFile = node->firstFile->nextSibling;
            free(temp);
            printf("File \"%s\" deleted successfully\n",fileName);
            return true;
        }
        else
        {
            while (temp != NULL)
            {
                if (temp->nextSibling != NULL && strcmp(temp->nextSibling->fileName,fileName) == 0)
                {
                    struct FileNode *temp1 = temp->nextSibling;
                    temp->nextSibling = temp->nextSibling->nextSibling;
                    free(temp1);
                    printf("File \"%s\" deleted successfully\n",fileName);
                    return true;
                }
                temp = temp->nextSibling;
            }

            return DeleteFile(node->firstDir,fileName); // if no file matched in the current directory
        }
    }
    else if (node == NULL)
    {
        return false; 
    }
    
    return (DeleteFile(node->firstDir,fileName)) ? true : DeleteFile(node->nextSibling,fileName);
}

// Read
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
        printf("%*c|--> %s\n ",n,' ',fileNode->fileName);
        printFiles(fileNode->nextSibling,n);
    }
}
