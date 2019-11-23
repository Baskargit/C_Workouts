#include <stdio.h>

int main()
{
	int testCaseCount;
    scanf("%d",&testCaseCount);
    
    for(int count=0; count<testCaseCount; count++)
    {
        unsigned int arraySize;
        scanf("%ud",&arraySize);

        long int array[arraySize];
        short int oddCount = 0;
        short int evenCount = 0;

        for (int i = 0; i < arraySize; i++)
        {
            scanf("%ld",&array[i]);
            
            // Step 1 : Get odd and even count
            if (array[i] % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }
        
        long int arrayNew[arraySize];
        int oddCounter = 0;
        int evenCounter = oddCount - 1;

        // Step 2 : Create a new array and order the numbers in odd and even format
        for (int i = 0; i < arraySize; i++)
        {
            if (array[i] % 2 == 0) {
                arrayNew[++evenCounter] = array[i];
            } else {
                arrayNew[oddCounter++] = array[i];
            }
        }

        // Step 3 : Sort Odd Part (Desc)
        for (int i = 0; i < oddCount; i++)
        {
            for (int j = i+1; j < oddCount; j++)
            {
                if (arrayNew[i] < arrayNew[j]) 
                {
                    long int temp = arrayNew[i];
                    arrayNew[i] = arrayNew[j];
                    arrayNew[j] = temp;
                }
                
            }
        }
        

        // Step 4 : Sort Even Part (Asc)
        for (int i = oddCount; i < arraySize; i++)
        {
            for (int j = i+1; j < arraySize; j++)
            {
                if (arrayNew[i] > arrayNew[j]) 
                {
                    long int temp = arrayNew[i];
                    arrayNew[i] = arrayNew[j];
                    arrayNew[j] = temp;
                }
                
            }
        }

        // Step 5 : Print array
        for (int i = 0; i < arraySize; i++)
        {
            printf("%ld ",arrayNew[i]);
        }
        
        printf("\n");
    }
    
	return 0;
}
