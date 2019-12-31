#include<stdio.h>
#include<stdbool.h>

void findRepeatednums(int size,int i,int j,int array[],int flag[]);

int main()
{
    // int array[] = {1,2,5,3,4,6,2,3,7};
    // int array[] = {1,2,1,3};
    // int array[] = {1,1,1,2};
    int array[] = {1,2,1,2,1,2};
    int flag[] = {1,1,1,1,1};
    findRepeatednums(sizeof(array)/sizeof(int),0,1,array,flag);
    printf("\n");

    return 0;
}

void findRepeatednums(int size,int i,int j,int array[],int flag[])
{
    if (i == size - 1)
    {
        return;
    }

    if (array[j] == array[i] && flag[j])
    {
        flag[j] = 0;
        printf("%d ",array[i]);
    }

    findRepeatednums(size,(j == size - 1) ? i+1 : i ,(j == size - 1) ? i+2 : j+1,array,flag);
}