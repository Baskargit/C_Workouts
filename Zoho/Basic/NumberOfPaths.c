/*
The problem is to count all the possible paths from top left to bottom right of a MxN matrix 
with the constraints that from each cell you can either move to "right" or "down".

Input
2
3 3
2 8

Output
6
8

Explanation:
Testcase 1: Let the given input 3*3 matrix is filled as such:
A B C
D E F
G H I
The possible paths which exists to reach 'I' from 'A' following above conditions are as follows:
ABCFI, ABEHI, ADGHI, ADEFI, ADEHI, ABEFI.

*/

// #include<stdio.h>

// void numberofpaths(int m,int n,int currentM,int currentN,int *count);

// int main()
// {
//     int m = 3,n = 3;
//     int count = 0;
    
//     numberofpaths(m,n,0,0,&count);
//     printf("\nCount : %d\n",count);
//     return 0;
// }

// void numberofpaths(int m,int n,int currentM,int currentN,int *count)
// {
//     printf("%d,%d\n",currentM,currentN);

//     if (currentM == m - 1 && currentN == n - 1)
//     {
//         *count += 1;
//         printf("count : %d\n\n",*count);
//         return;
//     }
//     else
//     {
//         if (currentN + 1 < n && currentM + 1 < m)
//         {
//             numberofpaths(m,n,currentM,currentN + 1,count);
//             return numberofpaths(m,n,currentM + 1,currentN,count);
//         }
//         else if(currentN + 1 >= n)
//         {
//             return numberofpaths(m,n,currentM + 1,currentN,count);
//         }
//         else if(currentM + 1 >= m)
//         {
//             return numberofpaths(m,n,currentM,currentN + 1,count);
//         }
             
//     }
// }

#include<stdio.h>

void numberofpaths(int m,int n,int currentM,int currentN,int *count);

int main()
{
    int m,n,count = 0;
    scanf("%d%d",&m,&n);
    
    numberofpaths(m,n,0,0,&count);
    printf("%d\n",count);
    return 0;
}

void numberofpaths(int m,int n,int currentM,int currentN,int *count)
{
    if (currentM == m - 1 && currentN == n - 1)
    {
        *count += 1;
        return;
    }
    else
    {
        if (currentN + 1 < n && currentM + 1 < m)
        {
            numberofpaths(m,n,currentM,currentN + 1,count);
            return numberofpaths(m,n,currentM + 1,currentN,count);
        }
        else if(currentN + 1 == n)
        {
            return numberofpaths(m,n,currentM + 1,currentN,count);
        }
        else if(currentM + 1 == m)
        {
            return numberofpaths(m,n,currentM,currentN + 1,count);
        }
    }
}
