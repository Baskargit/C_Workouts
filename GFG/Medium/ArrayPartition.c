/*
Subset Sum Problem
https://practice.geeksforgeeks.org/problems/subset-totalsum-problem/0

Given a set of numbers, check whether it can be partitioned into two subsets such that the totalsum of elements 
in both subsets is same or not.

Input:
4
1 5 11 5
3
1 3 5 

Output:
YES
NO

Explanation:
Testcase 1: There exists two subsets such that {1, 5, 5} and {11}.
*/

#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n],totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
        totalsum += arr[i];
    }

    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum1 = 0,sum2 = totalsum;

            if (i == 0) // length is 0
            {
                if (arr[j] == totalsum - arr[j]) {
                    printf("\nsum = %d\n",arr[j]);
                    flag = 1;
                    i = n;
                    break;
                }
            }
            else
            {
                int pos = 0,proceed = 0;
                // Till i
                for (int k = j; j+i < n && k < j+i; k++)
                {
                    proceed = 1;
                    pos = k;
                    sum1 += arr[k];
                    sum2 -= arr[k];

                    printf("sum1 = %d , sum2 = %d\n",sum1,sum2);

                    if (sum1 == sum2) {
                        printf("\nsum = %d\n",sum1);
                        flag = 1;
                        i = n;
                        break;
                    }
                    // printf("%d,",arr[k]);
                }printf(" ==> ");
                
                // After i
                int s1temp = sum1;
                int s2temp = sum2;
                for (int k = pos + 1; k < n && proceed; k++)
                {
                    s1temp = sum1 + arr[k];
                    s2temp = sum2 - arr[k];
                    // printf("%d,",arr[k]);
                    printf("sum1 = %d , sum2 = %d\n",s1temp,s2temp);
                    if (s1temp == s2temp) {
                        printf("\nsum = %d\n",s1temp);
                        flag = 1;
                        i = n;
                        break;
                    }
                }printf("\n");

                if (s1temp == s2temp) {
                    printf("\nsum = %d\n",s1temp);
                    flag = 1;
                    i = n;
                    break;
                }
            }
        }
        
    }
    

    printf("%s\n",(flag) ? "YES" : "NO");
    return 0;
}


/*
Input:
8
479 758 315 472 730 101 460 619

Its Correct output is:
YES

And Your Code's output is:
NO

Input:
15
87 56 43 91 27 65 59 36 32 51 37 28 75 7 74

Its Correct output is:
YES

And Your Code's output is:
NO

Input:
15
987 856 743 491 227 365 859 936 432 551 437 228 275 407 474

Its Correct output is:
YES

And Your Code's output is:
NO

*/
