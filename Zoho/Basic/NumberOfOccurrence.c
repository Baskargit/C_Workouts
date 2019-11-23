#include <stdio.h>

int main()
{
    int n;
    int k;
    int frequency = 0;

    scanf("%d %d",&n,&k);

    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d",&a);
        frequency = (a == k) ? frequency + 1 : frequency;
    }

    printf("%d\n",(frequency > 0) ? frequency : -1);
    
    return 0;
}
