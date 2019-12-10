#include <stdio.h>
#include <stdbool.h>

bool slidingtechnique(int n,int arr[],int *startindex,int *endindex,int sum);

int main()
{
    unsigned int n,s;
    scanf("%d%d",&n,&s);

    unsigned int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int i=0,j=0;
    bool found = false;
    while (i < n && !found)
    {
        unsigned int sum = arr[i];

        j = i + 1;
        while (j < n)
        {
            if(arr[j] + sum < s) {
                sum += arr[j];
                j++;
            } else if(arr[j] + sum == s) {
                found = true;
                break;
            } else {
                break;
            }
        }

        i++;
    }
    
    if(found) {
        printf("%d %d\n",--i,j);
    } else {
        printf("-1\n");
    }
    
    
    return 0;
}

// Efficient solution 
// Sliding Window technique (Not completed refer google)

bool slidingtechnique(int n,int arr[],int *startindex,int *endindex,int sum)
{
    int i = 0 , j = i;

    int front = 0;
    int currentsum = 0;
    while (i < n)
    {
        if(currentsum + arr[i] < sum) {
            sum += arr[i];
            i++;
        } else if(currentsum + arr[i] == sum) {
            *startindex = front + 1;
            *endindex = i + 1;
            return true;
        } else {
            while (front <= i)
            {
                if(sum - arr[front] > sum) 
                {
                    sum -= arr[front];
                    front++;
                } 
                else if(sum - arr[front] == sum) 
                {
                    *startindex = front + 1;
                    *endindex = i + 1;
                    return true;
                } 
                else {
                    i++;
                    currentsum = arr[i];
                    break;
                }
                front++;
            } 
        }

    }

    return false;
}