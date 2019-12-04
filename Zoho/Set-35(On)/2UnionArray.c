/*
Input :
3
5 3
1 2 3 4 5
1 2 3
6 2
85 25 1 32 54 6
85 2
6 5
1 1 2 2 3 3
8 9 7 6 5

Output
5
7
8
*/

#include<stdio.h>
#include<stdbool.h>

int main()
{
	int testCaseCount;
    scanf("%d",&testCaseCount);
    
    for(int count=0; count<testCaseCount; count++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        
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