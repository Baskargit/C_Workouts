// 10:36 - 11:29

// https://practice.geeksforgeeks.org/problems/decode-the-pattern/0

/*
Given a pattern as below and an integer n your task is to decode it and print nth row of it. 
The pattern follows as :
1
11
21
1211
111221

Example:
Input:
2
3
Output:
11
21

*/

#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    char num[1000];
    num[0] = '1';

    int pos = 0;
    for (int i = 1; i < n; i++)
    {
        int j = 0;
        char buffer[1000] = { '\0' };

        // copy the previous pattern
        while ((buffer[j] = num[j]) && num[j++] != '\0');

        // printf("%s\n",buffer);

        j = 0;
        pos = 0;
        while (buffer[j] != '\0')
        {
            int count = 1;

            while (buffer[j+1] == buffer[j])
            {
                count++;
                j++;
            }
            num[pos++] = '0' + count;
            num[pos++] = buffer[j];
            j++;
        }
        num[pos] = '\0';

    }

    printf("Pattern : %s\n",num);
    
    return 0;
}

