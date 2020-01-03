// https://practice.geeksforgeeks.org/problems/check-for-subsequence/0
// 0.09 execution time

#include <stdio.h>

int main()
{
    char s1[10000],s2[10000];
    scanf("%s%s",s1,s2);

    int previousindex = -1;
    int i=0,j=0,prei=0;

    while (s1[i] != '\0')
    {
        while (s2[j] != '\0')
        {
            if(s2[j] == s1[i] && j > previousindex) 
            {
                previousindex = j;
                prei = i;
                j++;
                break;
            }
            j++;
        }
        i++;
    }

    // printf("%s\n",(previousindex != -1 && s1[i-1] == s2[previousindex] && prei == i - 1) ? "1" : "0");
    printf("%s\n",(previousindex != -1 && prei == i - 1) ? "1" : "0");
    return 0;
}

/*
Conditions explanation
1 -> previousindex != -1 ====> If nothing matched
2 -> s1[i-1] == s2[previousindex] =====> removed
3 -> prei == i - 1 ====> if given string only matched the part of the pattern

Input (condition 1)
abc defgh

Input (condition 3)
gksrek gk 


Input:
LRBBMQBHCDARZOWKKYHIDDQSCDXRJMOWFRXSJYBLDBEFSARCBYNECDYGGXXPKLORELLNMPAPQFWKHOPKMCO
QHNWNKUEWHSQMGBBUQCLJJIVSWMDKQTBXIXMVTRRBLJPTNSNFWZQFJMAFADRRWSOFSBCNUVQHFFBSAQXWPQCAC

Its Correct output is:
0

And Your Code's output is:
1

*/
