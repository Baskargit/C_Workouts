#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr1[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr1[i]);
    }

    int index = 0;
    int flag = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int temp;
        scanf("%d",&temp);

        if(temp != arr1[i] && flag) {
            index = i;
            flag = 0;
        }
    }
    
    printf("%d\n",index);
    
    return 0;
}
