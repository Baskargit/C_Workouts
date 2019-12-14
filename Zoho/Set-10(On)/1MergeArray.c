/*
Merge two arrays without duplicates
*/
#include<stdio.h>

int main()
{
    int n1,n2;
    scanf("%d%d",&n1,&n2);

    int arr1[n1],arr2[n2],arr3[n1+n2];

    for (int i = 0; i < n1; i++)
    {
        scanf("%d",&arr1[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        scanf("%d",&arr2[i]);
    }

    int pos = 0;
    int previousvalue = 0;

    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if(arr1[i] < arr2[j]) 
        {
            arr3[pos++] = arr1[i++];
        }
        else if(arr2[j] < arr1[i])
        {
            arr3[pos++] = arr2[j++];
        }
        else
        {
            if(arr1[i] != previousvalue) 
            {
                previousvalue = arr1[i];
                arr3[pos++] = arr1[i++];
                j++;
            }
            else
            {
                i++;j++;
            }
            
        }
    }

    // Copy left over elements in arr1 and arr2 to arr3
    while (i < n1)
    {
        arr3[pos++] = arr1[i++];
    }

    while (j < n2)
    {
        arr3[pos++] = arr2[j++];
    }

    // Print merged
    for (int i = 0; i < pos; i++)
    {
        printf("%d ",arr3[i]);
    }
       
    printf("\n");
    return 0;
}

/*
Array1: [1, 2, 3, 6, 9]
Array2: [2, 4, 5, 10]
Merged Array: [1, 2, 3, 4, 5, 6, 9, 10]

5 4
1 2 3 6 9
2 4 5 10

6 4
1 2 3 4 5 6
11 22 33 44

8 4
1 2 3 4 5 6 7 8
11 22 33 44

*/