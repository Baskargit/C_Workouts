// Not completed

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main()
{
    char expression[] = "(a+b)(a*b)";
    int length = strlen(expression);

    char currentexpression[length];
    int cepos = 0;
    bool fromexpression = true;

    char stack[length];
    int pos = -1;

    for (int i = 0; i < length; i++)
    {
        // Push
        if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            stack[++pos] = expression[i];
        }
        else if(expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {
            // POP
            if(pos != -1 && expression[i] == ')' && stack[pos] == '(') 
            {
                stack[pos--] = '\0';
            }
            else if(pos != -1 && expression[i] == ']' && stack[pos] == '[')
            {
                stack[pos--] = '\0';
            }
            else if(pos != -1 && expression[i] == '}' && stack[pos] == '{')
            {
                stack[pos--] = '\0';
            }
            else
            {
                stack[++pos] = expression[i];
            }
        }
        else
        {
            currentexpression[cepos++] = expression[i];
        }
        
    }
    stack[++pos] = '\0';
    
    printf("%s\n",stack);
    printf("express : %s\n",currentexpression);
    
    if(strlen(stack))
    {
        printf("Invalid expression\n");
    }
    else
    {
        // validate operations

    }
    
    return 0;
}
