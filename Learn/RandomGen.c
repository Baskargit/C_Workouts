#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int ran = rand();
    
    for (int i = 1; i < 10; i++)
    {
        printf("%d\n",rand() % i + 1);
    }
    
    return 0;
}
