#include <stdio.h>
#include <string.h>

int getWeight(char roman);
int getValue(char roman);

int main()
{
	int testCaseCount;
    scanf("%d",&testCaseCount);
    
    for(int count=0; count<testCaseCount; count++)
    {
        char romanInput[32];
        scanf("%s",romanInput);
        int result = 0;

        for (int i = 0; i < strlen(romanInput);)
        {
            if (getWeight(romanInput[i + 1]) > getWeight(romanInput[i])) {
                result += (getValue(romanInput[i + 1]) - getValue(romanInput[i]));
                i += 2;
            } else {
                result += getValue(romanInput[i]);
                i++;
            } 
        }

        printf("%d\n",result);
    }
    
	return 0;
}

int inline getWeight(char roman)
{
    switch (roman)
    {
        case 'I':
            return 1;
        
        case 'V':
            return 2;

        case 'X':
            return 3;

        case 'L':
            return 4;

        case 'C':
            return 5;

        case 'D':
            return 6;

        case 'M':
            return 7;
        
        default:
            return 0;
    }

    return 0;
}

int inline getValue(char roman)
{
    switch (roman)
    {
        case 'I':
            return 1;
        
        case 'V':
            return 5;

        case 'X':
            return 10;

        case 'L':
            return 50;

        case 'C':
            return 100;

        case 'D':
            return 500;

        case 'M':
            return 1000;
        
        default:
            return 0;
    }

    return 0;
}
