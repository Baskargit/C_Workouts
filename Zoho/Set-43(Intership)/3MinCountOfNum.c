/*
Q.no.3
Given a number N. find the minimum minCount of numbers in which N can be represented as a 
sum of numbers x1, x2, … xn. where xi is number whose digits are 0s and 1s.

example 1)  i/p :  N = 33

o/p : minCount = 3. => 33( 11 + 11 + 11 )

some other possibilities of 33 is 
(11 + 11 + 10 + 1),
(11 + 10 + 10 + 1 + 1 ),
(10 + 10 + 10 + 1 + 1 + 1)
*/

#include<stdio.h>
#include<stdbool.h>

int get01Numbers(int n,int currentN,int numbers[],int counter);
bool is01Num(int currentN);
void print01Numbers(int numbers[],int numbers01Count);

int main()
{
    int n = 456;
    int numbers01[n];
    int numbers01Count = get01Numbers(n,0,numbers01,0);
    int minCount = __INT_MAX__;

    print01Numbers(numbers01,numbers01Count);

    for (int i = numbers01Count - 1; i >= 0; i--)
    {
        int sum = 0;
        int tempcounter = 0;

        for (int j = i; j >= 0;)
        {
            if (sum + numbers01[j] == n)
            {
                tempcounter++;
                minCount = (tempcounter < minCount) ? tempcounter : minCount;
                break;
            }
            else if (numbers01[j] == 0)
            {
                break;
            }
            else if (sum + numbers01[j] < n)
            {
                sum += numbers01[j];
                tempcounter++;
            }
            else
            {
                j--;
            }
        }
    }
    
    printf("Minimum minCount of numbers : %d\n",minCount);
    return 0;
}

int get01Numbers(int n,int currentN,int numbers[],int counter)
{
    if (currentN > n)
    {
        return counter;
    }
    else
    {
        int temp = currentN;
        bool is01Number = is01Num(currentN);

        if (is01Number)
        {
            numbers[counter] = currentN;
        }
        
        return get01Numbers(n,currentN+1,numbers,(is01Number) ? counter + 1 : counter);
    }
}

bool is01Num(int currentN)
{
    return (currentN == 0 || currentN == 1)
           ? true
           : (currentN % 10 == 0 || currentN % 10 == 1) ? is01Num(currentN / 10) : false;
}

void print01Numbers(int numbers[],int numbers01Count)
{
    printf("01 Numbers are : ");

    for (int i = 0; i < numbers01Count; i++)
    {
        printf("%d ",numbers[i]);
    }

    printf("\n");
}