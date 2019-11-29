/*
Evaluate the expression and sort and print the output. Getting the input is the tricky part

Input:

Number of input : 4


2*3

2^2^2

35

3*1

Output:

3*1

2*3

2^2^2

35
*/

// optimized soln : https://www.geeksforgeeks.org/expression-evaluation/

///////////// Brutforce approach ////////////////

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter total test cases : ");
    scanf("%d",&n);

    char input[n][1000];
    int results[n];
    int mastercounter = 0;

    // Input pointer
    char *inputptr[n];

    while (n--)
    {
       char expression[1000];
       scanf("%s",expression);

       strcpy(input[mastercounter],expression);

        // pare input expression
        int i = 0;
        bool firsttime = true;
        int firstoperandvalue = 0;

        while (expression[i] != '\0')
        {
            char number[64];
            int numbercounter = 0;

            number[numbercounter++] = expression[i];

            // first operand for the first time only
            if (firsttime)
            {
                firsttime = false;
                while (isdigit(expression[++i]))
                {
                    number[numbercounter++] = expression[i];
                }
                number[numbercounter] = '\0';
                printf("First Number : %s\n",number);
                firstoperandvalue = atoi(number);  
            }
            number[numbercounter] = '\0';
            printf("firstoperandvalue : %d\n",firstoperandvalue);
            
            
            // operator
            char operator = expression[i];
            printf("Operator : %c\n",operator);

            // second operand
            numbercounter = 0;
            number[numbercounter++] = expression[++i];

            while (isdigit(expression[++i]))
            {
                number[numbercounter++] = expression[i];
            }
            number[numbercounter] = '\0';
            printf("Second Number : %s\n",number);
            
            int secondoperandvalue = atoi(number);
            printf("secondoperandvalue : %d\n",secondoperandvalue);

            // Find out the operation
            // Store restult
            switch (operator)
            {
                case '*':
                    results[mastercounter] = firstoperandvalue * secondoperandvalue;
                    firstoperandvalue = results[mastercounter];
                    break;
                case '/':
                    results[mastercounter] = firstoperandvalue / secondoperandvalue;
                    firstoperandvalue = results[mastercounter];
                    break;
                case '+':
                    results[mastercounter] = firstoperandvalue + secondoperandvalue;
                    firstoperandvalue = results[mastercounter];
                    break;
                case '-':
                    results[mastercounter] = firstoperandvalue - secondoperandvalue;
                    firstoperandvalue = results[mastercounter];
                    break;
                case '%':
                    results[mastercounter] = firstoperandvalue % secondoperandvalue;
                    firstoperandvalue = results[mastercounter];
                    break;
                case '^':
                    results[mastercounter] = pow(firstoperandvalue,secondoperandvalue);
                    firstoperandvalue = results[mastercounter];
                    break;
                
                default:
                    results[mastercounter] = firstoperandvalue;
                    break;
            }

            printf("i : %d\n\n",i);
        }

        mastercounter++;
    }

    printf("Mastercounter : %d\n",mastercounter);

    printf("\nParsed values :\n");
    for (int i = 0; i < mastercounter; i++)
    {
        printf("%s => %d\n",input[i],results[i]);
    }

    
    for (int i = 0; i < mastercounter; i++)
    {
        inputptr[i] = input[i]; 
    }
    printf("\nInput ptr result :\n");
    for (int i = 0; i < mastercounter; i++)
    {
        printf("%p\n",inputptr[i]);
    }

    // Bubble sort
    for (int i = 0; i < mastercounter; i++)
    {
        for (int j = i+1; j < mastercounter; j++)
        {
            if (results[j] < results[i])
            {
                int temp = results[i];
                results[i] = results[j];
                results[j] = temp;

                char *tempptr = inputptr[i];
                inputptr[i] = inputptr[j];
                inputptr[j] = tempptr; 
            }
        }
    }
    
    // Print final result
    printf("\nFinal result :\n");
    for (int i = 0; i < mastercounter; i++)
    {
        printf("%s => %d\n",inputptr[i],results[i]);
    }
    
    return 0;
}