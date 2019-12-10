/*
1) Find the minimum number of times required to represent a number as sum of squares.

12 = 1^2 + 1^2 + 1^2 + 1^2 + 1^2 + 1^2 + 
    1^2 + 1^2 + 1^2 + 1^2 + 1^2 + 1^2 
12 = 2^2 + 2^2 + 2^2
12 = 3^2 + 1^2 + 1^2

Input: 12
Output: min: 3

*/

#include <stdio.h>
#include <math.h>

int main()
{
    int n = 5;

    int mintimes = n;
    int num = 1;

    while (1)
    {
        if(pow(num,2) <= n)
        {
            int sum = 0;
            int counter = 0;
            int tempnum = num;
            while (sum <= n && tempnum >= 1)
            {
                int tempsum = pow(tempnum,2);

                if(sum + tempsum == n) {
                    counter++;
                    break;
                } else if(sum + tempsum < n) {
                    sum += tempsum;
                    counter++;
                } else {
                    tempnum--;
                }
            }

            mintimes = (counter < mintimes) ? counter : mintimes;
            num++;
        } else {
            break;
        }
        
    }

    printf("%d\n",mintimes);
    
    
    return 0;
}
