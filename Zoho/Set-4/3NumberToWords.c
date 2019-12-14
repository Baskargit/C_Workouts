//https://practice.geeksforgeeks.org/problems/number-to-words/0

// Long and messy soln
// Not an efficient one
// All the if else can be replaced by functions
// Efficient soln : https://www.geeksforgeeks.org/convert-number-to-words/
#include<stdio.h>
#include<string.h>

int main()
{
    char num[5];
    scanf("%s",num);

    char ones[][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

    char tens[][10] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};

    char tens1[][10] = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

    int length = strlen(num);

    if (length == 1)
    {
        printf("%s",ones[num[0] - '0']);
    }
    else if(length == 2)
    {
        if(num[0] == '1') {
            printf("%s",tens[num[1] - '0']);
        }
        else
        {
            if(num[1] != '0') {
                printf("%s %s",tens1[num[0] - '0'],ones[num[1] - '0']);
            }
            else
            {
                printf("%s",tens1[num[0] - '0']);
            } 
        }
    }
    else if(length == 3)
    {
        printf("%s hundred",ones[num[0] - '0']);

        if(num[1] != '0' || num[2] != '0') 
        {
            printf(" and ");

            if(num[1] == '0') 
            {
                printf("%s",ones[num[2] - '0']);
            }
            else if(num[1] == '1') 
            {
                printf("%s",tens[num[2] - '0']);
            }
            else
            {
                if(num[2] != '0') {
                    printf("%s %s",tens1[num[1] - '0'],ones[num[2] - '0']);
                }
                else
                {
                    printf("%s",tens1[num[1] - '0']);
                } 
            }
        }
    }
    else
    {
        printf("%s thousand",ones[num[0] - '0']);

        if(num[1] != '0' || num[2] != '0' || num[3] != '0') 
        {
            if(num[1] != '0')
            {
                printf(" %s hundred",ones[num[1] - '0']);

                if(num[2] != '0' || num[3] != '0') 
                {
                    printf(" and ");

                    if(num[2] == '0') 
                    {
                        printf("%s",ones[num[3] - '0']);
                    }
                    else if(num[2] == '1') 
                    {
                        printf("%s",tens[num[3] - '0']);
                    }
                    else
                    {
                        if(num[3] != '0') {
                            printf("%s %s",tens1[num[2] - '0'],ones[num[3] - '0']);
                        }
                        else
                        {
                            printf("%s",tens1[num[2] - '0']);
                        } 
                    }
                }
            }
            else
            {
                if(num[2] == '0') 
                {
                    printf(" %s",ones[num[3] - '0']);
                }
                else if(num[2] == '1') 
                {
                    printf(" %s",tens[num[3] - '0']);
                }
                else
                {
                    if(num[3] != '0') {
                        printf(" %s %s",tens1[num[2] - '0'],ones[num[3] - '0']);
                    }
                    else
                    {
                        printf(" %s",tens1[num[2] - '0']);
                    } 
                }
            }
            
        }
    }
    
    printf("\n");
    return 0;
}

/*
Corner cases
717
10
1000
505
36
19
2105
1008
100
9999
3037
0
*/
