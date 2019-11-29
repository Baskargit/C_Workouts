/*
link : https://www.geeksforgeeks.org/zoho-interview-experience-set-39-on-campus-drive-for-software-developer/

4. Matrix Diagonal sum
Given a matrix print the largest of the sums of the two triangles split by diagonal from top right to bottom left

I/P:

3 3
1 2 3
4 5 6
7 8 9

O/P: 38
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int m,n;
    m=3,n=3;

    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    int t1 = 0;
    int t2 = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == (n - 1) - i) {
                t1 += matrix[i][j];
                t2 += matrix[i][j];
                printf("%d%d ",i,j);
            } else if(j < (n - 1) - i) {
                t1 += matrix[i][j];
                printf("%d%d ",i,j);
            } else {
                t2 += matrix[i][j];
                printf("%d%d ",i,j);
            }   
        }
        printf("\n");
    }

    printf("%d\n",(t1 > t2) ? t1 : t2);
    return 0;
}


