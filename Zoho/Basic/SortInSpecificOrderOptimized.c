#include <stdio.h>

int main()
{
	int testCaseCount;
    scanf("%d",&testCaseCount);
    
    for(int count=0; count<testCaseCount; count++)
    {
        unsigned int arraySize;
        scanf("%ud",&arraySize);

        long int oddArray[arraySize];
        long int evenArray[arraySize];

        int oddCounter = 0;
        int evenCounter = 0;

        for (int i = 0; i < arraySize; i++)
        {
            long int data;
            scanf("%ld",&data);
            
            // Step 1 : Get odd and even count
            if (data % 2 == 0) {
                evenArray[evenCounter++] = data;
            } else {
                oddArray[oddCounter++] = data;
            }

            // Step 2 : Sort Odd Part (Desc)
            for (int i = 0; i < oddCounter; i++)
            {
                for (int j = i+1; j < oddCounter; j++)
                {
                    if (oddArray[i] < oddArray[j]) 
                    {
                        long int temp = oddArray[i];
                        oddArray[i] = oddArray[j];
                        oddArray[j] = temp;
                    }
                    
                }
            }

            // Step 3 : Sort Even Part (Asc)
            for (int i = 0; i < evenCounter; i++)
            {
                for (int j = i+1; j < evenCounter; j++)
                {
                    if (evenArray[i] > evenArray[j]) 
                    {
                        long int temp = evenArray[i];
                        evenArray[i] = evenArray[j];
                        evenArray[j] = temp;
                    }
                    
                }
            }
        }

        // Step 5 : Print array
        for (int i = 0; i < oddCounter; i++)
        {
            printf("%ld ",oddArray[i]);
        }

        // Step 5 : Print array
        for (int i = 0; i < evenCounter; i++)
        {
            printf("%ld ",evenArray[i]);
        }
        
        printf("\n");
    }
    
	return 0;
}
