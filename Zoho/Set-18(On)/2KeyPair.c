#include <stdio.h>
#include <stdbool.h>

bool iskeypairfound(int *arr,int size,int sum)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                return true;
            }
            
        }
    }

    return false;
}

int main()
{
	int testCaseCount;
    scanf("%d",&testCaseCount);
    
    for(int count=0; count<testCaseCount; count++)
    {
        int n,x;
        scanf("%d %d",&n,&x);
        int arr[n];
        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
        }

        printf("%s\n",iskeypairfound(arr,n,x) ? "Yes" : "No");
    }
    
	return 0;
}