#include<stdio.h>
#include<string.h>

int main()
{
    char expression[] = "((abc)(de))";
    int length = strlen(expression);
    printf("length : %d\n",length);

    char stack[length];
    int pos = -1;

    for (int i = 0; i < length; i++)
    {
        if(expression[i] == '(')
        {
            stack[++pos] = expression[i];
        }
        else if(expression[i] == ')')
        {
            // POP
            if(pos != -1 && stack[pos - 1] == '(') 
            {
                printf("pos : %d\n",pos);
                stack[pos--] = '\0';
            }
            else
            {
                stack[++pos] = expression[i];
            }
        }
    }
    stack[++pos] = '\0';
    
    printf("Stack : %s\n",stack);
    return 0;
}
