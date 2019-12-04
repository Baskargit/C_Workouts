/*
3. It’s about anagram.i/p was array of strings .and a word was given to find whether it has anagram in given array.

I/p catch, got, tiger, mat, eat, Pat, tap, tea


Word: ate

O/p eat, tea
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char strings[][10] = {"catch", "got", "tiger", "mat", "eat", "Pat", "tap", "tea"};
    char word[] = "ate";

    int n = sizeof(strings)/10;

    int value = 0;
    int wordlength = strlen(word);
    for (int i = 0; i < n ; i++)
    {
        int strlength = strlen(strings[i]);
        if (wordlength == strlength)
        {
            int value = 0;
            for (int j = 0; j < wordlength; j++)
            {
                value = value ^ strings[i][j];
                value = value ^ word[j];
            }

            printf("%s ",(value == 0) ? strings[i] : "\0");
        }
    }

    printf("\n");
    

    return 0;
}


// Using Bit manuplation
// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	int testCaseCount;
//     scanf("%d",&testCaseCount);
    
//     for(int count=0; count<testCaseCount; count++)
//     {
//         char s1[1000000];
//         char s2[1000000];
//         scanf("%s %s",s1,s2);
                
//         int value = 1;
//         long int s1length = strlen(s1);
//         long int s2length = strlen(s2);

//         if (s1length == s2length)
//         {
//             value = 0;
//             for (int i = 0; i < s1length; i++)
//             {
//                 value ^= s1[i];
//                 value ^= s2[i];
//                 printf("%d ",value);
//             }
//         }
        
//         printf("%s\n",(value) ? "NO" : "YES");
//     }
    
// 	return 0;
// }
