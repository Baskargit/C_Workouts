#include<stdio.h>
#include<string.h>

int main()
{
    char expression[] = "(((ab)";
    int length = strlen(expression);
    printf("length : %d\n",length);

    char stack[length];
    char stackpos[length];
    int pos = -1;

    for (int i = 0; i < length; i++)
    {
        if(expression[i] == '(')
        {
            stack[++pos] = expression[i];
            stackpos[pos] = i;
        }
        else if(expression[i] == ')')
        {
            // POP
            if(pos != -1 && stack[pos] == '(') 
            {
                // printf("pos : %d\n",pos);
                stack[pos--] = '\0';
            }
            else
            {
                stack[++pos] = expression[i];
                stackpos[pos] = i;
            }
        }
    }
    stack[++pos] = '\0';
    
    printf("Stack : %s\n",stack);
    for (int i = 0; i < pos; i++)
    {
        printf("%c --> %d\n",stack[i],stackpos[i]);
    }
    
    return 0;
}
