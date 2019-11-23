#include <stdio.h>
#include <stdbool.h>

bool IsPerfectSquare(int n);
bool IsMulOf4AndDivOf6(int n);
bool IsEvenNumber(int n);

int main()
{
    int numbers[] = {10,36,54,89,12,24};
    int weight[] = {0,0,0,0,0,0};
    int length = sizeof(numbers)/sizeof(int);

    for (int i = 0; i < length; i++)
    {
        // Get weights
        weight[i] += (IsPerfectSquare(numbers[i])) ? 5 : 0;
        weight[i] += (IsMulOf4AndDivOf6(numbers[i])) ? 4 : 0;
        weight[i] += (IsEvenNumber(numbers[i])) ? 3 : 0;
    }

    // Sort weights (asc to desc)
    for (int i = 0; i < length; i++)
    {
        for (int j = i+1; j < length; j++)
        {
            if (weight[j] < weight[i])
            {
                int wTemp = weight[j];
                weight[j] = weight[i];
                weight[i] = wTemp;

                int nTemp = numbers[j];
                numbers[j] = numbers[i];
                numbers[i] = nTemp;
            }
            
        }
        
    }
     

    // Display the output
    for (int i = 0; i < length; i++)
    {
        printf("<%d,%d>\n",numbers[i],weight[i]);
    }
    
    return 0;
}

bool IsPerfectSquare(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }

    return false;
}

bool IsMulOf4AndDivOf6(int n)
{
    return (n%4 == 0 && n%6 == 0) ? true : false;
}

bool IsEvenNumber(int n)
{
    return (n%2 == 0 ) ? true : false;
}