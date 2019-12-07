#include <stdio.h>

int main()
{
    int num = 0;
    int oddcount = 0, evencount = (num == 0) ? 1 : 0;

    while (num > 0)
    {
        if((num % 10) % 2 == 0) {
            evencount++;
        } else {
            oddcount++;
        }
        num /= 10;
    }

    printf("ODD : %d\nEVEN : %d\n",oddcount,evencount);
    
    return 0;
}
