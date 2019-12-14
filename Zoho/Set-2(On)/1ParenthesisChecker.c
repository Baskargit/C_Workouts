// Execution Time:0.05 - in gfg
// https://practice.geeksforgeeks.org/problems/parenthesis-checker/0

#include<stdio.h>
#include<string.h>

int main()
{
    char expression[] = "(()";
    int length = strlen(expression);
    printf("length : %d\n",length);

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
    }
    stack[++pos] = '\0';
    
    printf("%s\n",stack);
    printf("Stack : %s\n",(strlen(stack) == 0) ? "balanced" : "not balanced");
    return 0;
}
