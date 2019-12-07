/*

Input: 
6
1 10 6 8 13 21

Output: 1 8 13 21
---------------------------------
Input: 
4
2 10 4 8

Output: 
2 8 
*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    
    int min = 0,max = 0;
    int temp;
    if(n > 0) {
        scanf("%d",&temp);
        min = temp; max = temp;
        arr[0] = temp;
    }

    for (int i = 1; i < n; i++)
    {
        scanf("%d",&temp);

        if(temp < min) {
            min = temp;
        }else if(temp > max) {
            max = temp;
        }

        arr[i] = temp;
    }

    // Find fibonacci
    int prev = 0;
    int next = 1;

    for (int i = 0; next <= max; i++)
    {
        temp = next;
        next += prev;
        prev = temp;
        
        if(next >= min && next <= max) 
        {
            for (int j = 0; j < n; j++)
            {
                if(arr[j] == next) {
                    printf("%d ",next);
                    // break;
                }        
            }
            
        }
    }

    printf("\n");
    return 0;
}
