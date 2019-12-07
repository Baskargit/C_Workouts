#include<stdio.h>
#include<stdbool.h>

int main()
{
	int testCaseCount;
    scanf("%d",&testCaseCount);
    
    for(int count=0; count<testCaseCount; count++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        
        int arr[n+m];
        int uniquecount = 0;
        bool flag = true;
        for(int i=0; i<n+m ; i++)
        {
            int temp;
            scanf("%d",&temp);
            
            for(int j=0; j<i; j++)
            {
                if(temp == arr[j]) {
                   flag = false;
                   break;
                }
            }

            if (flag)
            {
                arr[uniquecount++] = temp;
            }
            
            flag = true;
        }

        printf("%d\n",uniquecount);
    }
    
	return 0;
}