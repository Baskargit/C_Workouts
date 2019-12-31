#include<stdio.h>

int greatestvalue(int n,int arr[n]);

int main()
{
    int arr[] = {31,4,2,6,8,20,7,2,5};

    printf("Greatest number : %d\n",greatestvalue(sizeof(arr)/sizeof(int) - 1,arr));
    return 0;
}

int greatestvalue(int n,int arr[n])
{
    if (n == 0)
    {
        return arr[0];
    }
    
    int maxvalue = greatestvalue(n - 1,arr);

    return (maxvalue > arr[n]) ? maxvalue : arr[n];
}
