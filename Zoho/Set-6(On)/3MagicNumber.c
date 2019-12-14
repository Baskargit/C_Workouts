// 2:43
// https://www.geeksforgeeks.org/find-nth-magic-number/
// https://practice.geeksforgeeks.org/problems/faithful-numbers/0
// Brutforce approach
#include<stdio.h>
#include<math.h>

int main()
{
    int n = 10000;

    unsigned long long int nmagicnum;
    int magicnumcount = 0;

    unsigned long long int sevenpowers[100];

    for (int i = 1; i <= 23; i++)
    {
        sevenpowers[i] = powl(5,i);
    }

    for (unsigned long long int i = 1; magicnumcount < n; i++)
    {
        unsigned long long int num = i;
        unsigned long long int sum = 0;

        for (int j = 23; j >= 0; j--)
        {
            if(sevenpowers[j] + sum < num) {
                sum += sevenpowers[j];
            }
            else if(sevenpowers[j] + sum == num) {
                sum += sevenpowers[j];
                printf("i = %lld , sum = %lld , magicnumcount = %d\n",i,sum,magicnumcount);
                magicnumcount++;
                nmagicnum = i;
                break;
            }
        }
    }

    printf("\n%lld\n",nmagicnum);
    return 0;
}

/*
Input:
923589

Its Correct output is:
13259953468092899

And My Output is:
13259953468092898
*/
