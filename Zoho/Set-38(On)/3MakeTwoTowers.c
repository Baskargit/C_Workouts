/*
Given a 6 blocks, of different height h1, …, h6 . 
Make 2 towers using 3 Blocks for each tower in desired height h1, h2. 
Print the blocks to be used in ascending order

Input:

1 2 5 4 3  6

height of tower: 6 15

Output :

1 2 3 & 4 5 6
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void bubblesort(int *arr,int size);
void printarray(int *arr,int size);

int main()
{    
    int h[6] = {12,223,523,41,31,64};

    int t1[3],t2[3];
    int h1 = 266 , h2 = 628;

    if (h[0] + h[1] + h[2] == h1) {
        t1[0] = h[0];
        t1[1] = h[1];
        t1[2] = h[2];

        // Fill t2
        int k = 0;
        for (int i = 0; i < 6; i++)
        {
            if (h[i] != t1[0] && h[i] != t1[1] && h[i] != t1[2])
            {
                t2[k++] = h[i];
            }
        }
    } else if(h[0] + h[1] + h[2] == h2) {
        t2[0] = h[0];
        t2[1] = h[1];
        t2[2] = h[2];

        // Fill t1
        int k = 0;
        for (int i = 0; i < 6; i++)
        {
            if (h[i] != t2[0] && h[i] != t2[1] && h[i] != t2[2])
            {
                t1[k++] = h[i];
            }
        }
    } else {
        bool found = false;

        // 1 => 2 comb
        int i = 0;
        while (i < 3 && !found)
        {
            int j = 3;
            while (j < 6 && !found)
            {
                int k = j + 1;
                while (k < 6 && !found)
                {
                    if (h[i]+h[j]+h[k] == h1) {
                        t1[0] = h[i];
                        t1[1] = h[j];
                        t1[2] = h[k];
                        found = true;
                        
                        // Fill t2
                        k = 0;
                        for (int i = 0; i < 6; i++)
                        {
                            if (h[i] != t1[0] && h[i] != t1[1] && h[i] != t1[2])
                            {
                                t2[k++] = h[i];
                            }
                        }
                        break;
                        
                    } else if (h[i]+h[j]+h[k] == h2) {
                        t2[0] = h[i];
                        t2[1] = h[j];
                        t2[2] = h[k];
                        found = true;
                        
                        // Fill t1
                        k = 0;
                        for (int i = 0; i < 6; i++)
                        {
                            if (h[i] != t2[0] && h[i] != t2[1] && h[i] != t2[2])
                            {
                                t1[k++] = h[i];
                            }
                        }
                        break;
                    }
                    k++;
                }
                j++;
            }
            i++;
        }
    }

    // sort t1 and t2
    bubblesort(t1,3);
    bubblesort(t2,3);

    // print t1 t2
    printarray(t1,3);
    printarray(t2,3);
    
    printf("\n");
    return 0;
}


void bubblesort(int *arr,int size)
{
    // Bubble sort
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp; 
            }
        }   
    }
}

void printarray(int *arr,int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
