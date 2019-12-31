// Count the number of Positive and Negative numbers using struct
// This same could be achieved by passing the two variables as pointers params to the same function by replacing the struct

#include<stdio.h>

struct count
{
    int positivenumcount;
    int negativenumcount;
};

void getcount(struct count *count,int n,int arr[n],int pos);

int main()
{
    int arr[] = {1,2,-1,-23,-45,3,5,9,10,-4,-90};

    struct count count;
    count.positivenumcount = 0;
    count.negativenumcount = 0;

    getcount(&count,sizeof(arr)/sizeof(int),arr,0);
    printf("+ve = %d\n-ve = %d\n",count.positivenumcount,count.negativenumcount);
    return 0;
}

void getcount(struct count *count,int n,int arr[n],int pos)
{
    count->positivenumcount += (arr[pos] > 0) ? 1 : 0;
    count->negativenumcount += (arr[pos] < 0) ? 1 : 0;

    if (pos == n - 1) {
        return;
    }
    
    getcount(count,n,arr,pos + 1);    
}
