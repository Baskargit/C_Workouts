/*
Q.no.5)   Given an array of integers, write a program to re-arrange the array in the given form.

1st_largest, 1st_smallest, 2nd_largest, 2nd_smallest, 3rd_largest ……. etc.

*/

#include<stdio.h>

void arrangeArray(int n,int array[n],int newArray[n],int front,int rear,int currentN);
void printNewArray(int n,int newArray[n],int currentN);

int main()
{
    int n = 6;
    // int array[] = {1,2,3,4,5};
    int array[] = {1,2,3,4,5,6};
    int newArray[n];

    arrangeArray(n,array,newArray,0,n - 1,0);
    printNewArray(n,newArray,0);
    return 0;
}

void arrangeArray(int n,int array[n],int newArray[n],int front,int rear,int currentN)
{
    if (front > rear)
    {
        return;
    }
    else if (front == rear)
    {
        newArray[currentN] = array[front];
        return;
    }
    else
    {
        newArray[currentN] = array[rear];
        newArray[currentN + 1] = array[front];
        return arrangeArray(n,array,newArray,front + 1,rear - 1,currentN + 2);
    }
}

void printNewArray(int n,int newArray[n],int currentN)
{
    if (currentN == n)
    {
        printf("\n");
        return;
    }
    else
    {
        printf("%d ",newArray[currentN]);
        printNewArray(n,newArray,currentN + 1);
    }
}