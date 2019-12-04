/*
link : https://practice.geeksforgeeks.org/problems/next-larger-popedelement/0

Find the next greater popedelement for each popedelement in given array.

input: array[]={6, 3, 9, 10, 8, 2, 1, 15, 7};
output: {7, 5, 10, 15, 9, 3, 2, _, 8}

*/

// #include <stdio.h>
// #include <stdbool.h>

// Time Complexity: O(n^2). The worst case occurs when all popedelements are sorted in decreasing order.
// int main()
// {
//     int n = 4;

//     int arr[] = {1,3,2,4};

//     for (int i = 0; i < n; i++)
//     {
//         int largerpopedelement = -1;
//         for (int j = i+1; j < n; j++)
//         {
//             if (arr[j] > arr[i])
//             {
//                 largerpopedelement = arr[j];
//                 break;
//             }
            
//         }
//         printf("%d ",largerpopedelement);
//     }

//     printf("\n");
    
//     return 0;
// }

// Approach 2 using STACK

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACKSIZE 100

struct stack
{
    int top;
    int items[];
};

// Stack Functions to be used by printNGE()
void push(struct stack *ps, int x) 
{ 
    if (ps->top == STACKSIZE-1) 
    { 
        printf("Error: stack overflown \n"); 
        getchar(); 
        exit(0); 
    } 
    else
    { 
        ps->top += 1; 
        ps->items [ps->top] = x; 
    } 
} 

int pop(struct stack *ps) 
{ 
    int temp; 
    if (ps->top == -1) 
    { 
        printf("Error: stack underflow \n");
        getchar();
        exit(0);
    } 
    else
    {
        temp = ps->items [ps->top]; 
        ps->top -= 1; 
        return temp; 
    } 
}

bool isEmpty(struct stack *ps) 
{ 
    return (ps->top == -1)? true : false; 
} 
  
int main()
{
    int n = 5;

    int arr[] = {4, 5, 2, 25, 10};

    struct stack *sp = (struct stack *)malloc(sizeof(struct stack) + sizeof(int) * n);
    sp->top = -1;

    int popedelement, next;

    // push arr[0]
    push(sp,arr[0]);

    for (int i = 1; i < n; i++)
    {
        next = arr[i];

        if (!isEmpty(sp))
        {
            // if stack is not empty, then pop an element from stack 
            popedelement = pop(sp);

            /* If the popped popedelement is smaller than next, then 
                a) print the pair 
                b) keep popping while popedelements are smaller and 
                stack is not empty */
            while (popedelement < next) 
            { 
                printf("%d --> %d\n", popedelement, next); 

                if(isEmpty(sp)){
                    break;
                } 
                   
                popedelement = pop(sp); 
            }

            /* If popedelement is greater than next, then push 
               the popedelement back */
            if (popedelement > next) {
                push(sp, popedelement);
            }
        }

        /* push next to stack so that we can find 
           next greater for it */
        push(sp, next);        
    }
    
    /* After iterating over the loop, the remaining 
       popedelements in stack do not have the next greater 
       popedelement, so print -1 for them */
    while (!isEmpty(sp)) 
    { 
        popedelement = pop(sp); 
        next = -1; 
        printf("%d --> %d\n", popedelement, next); 
    }

    return 0;
}

