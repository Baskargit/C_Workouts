// https://practice.geeksforgeeks.org/problems/sum-of-prime/0/
// 2.11 Sec of exe time

#include<stdio.h>

int getPrimeCount(int n,int primes[],int currentN,int primecount);
void printPrimes(int primecount,int primes[primecount]);

int main()
{
    int n;
    scanf("%d",&n);

    int primes[n];
    int primeCount = getPrimeCount(n,primes,2,0);
    printPrimes(primeCount,primes);

    int flag,num1 = 0,num2 = 0;
    for (int i = 0; i < primeCount; i++)
    {
        if (primes[i] < n)
        {
            for (int j = i; j < primeCount; j++)
            {
                if (primes[i] + primes[j] == n)
                {
                    flag = 1;
                    num1 = primes[i];
                    num2 = primes[j];
                    i = primeCount;
                    break;
                }
            }
        }
        else
        {
            flag = 0;
            break;
        }
    }
    
    if (flag)
    {
        printf("%d %d\n",num1,num2);
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}

int getPrimeCount(int n,int primes[],int currentN,int primecount)
{
    if (currentN < n)
    {
        int flag = 1;

        for (int i = 2; i < currentN; i++)
        {
            if (currentN % i == 0)
            {
                flag = 0;
                break;
            }
        }
        
        if (flag)
        {
            primes[primecount] = currentN;
            return getPrimeCount(n,primes,currentN + 1,primecount + 1);
        }
        else
        {
            return getPrimeCount(n,primes,currentN + 1,primecount);
        }   
    }
    else
    {
        return primecount;
    }
}

void printPrimes(int primecount,int primes[primecount])
{
    printf("Primes till %d:\n",primecount);
    for (int i = 0; i < primecount; i++)
    {
        printf("%d ",primes[i]);
    }
    printf("\n");
}