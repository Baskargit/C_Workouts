// Accepted answer

#include <stdio.h>

void printspirally(int rows,int cols,int matrix[rows][cols]);

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);

    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    

    printspirally(m,n,a);
    printf("\n");

    return 0;
}

void printspirally(int rows,int cols,int matrix[rows][cols])
{
    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int ti,tjs,tje;
    int rj,ris,rie;
    int bi,bjs,bje;
    int lj,lis,lie;

    ti = 0,tjs = 0,tje = cols - 1;
    rj = cols - 1,ris = ti + 1,rie = rows - 1;
    bi = rows - 1,bjs = cols - 1,bje = 0;
    lj = 0 , lis = rows - 1, lie = ti;

    int i,j; // iterators

    int proceed = 1;
    while (proceed)
    {
        proceed = 0;

        if(ti > bi) { return; } // Major corner case

        // Top
        if(ti <= bi)
        {
            proceed = 1;
            i = ti; j = tjs;
            while (j <= tje) { printf("%d ",matrix[i][j++]); }

            if(ti == bi) { return; }
        }

        // Right
        if(rj >= lj)
        {
            proceed = 1;
            j = rj, i = ris;

            while (i < rie) { printf("%d ",matrix[i++][j]); }

            if(rj == lj) { printf("%d ",matrix[i][j]);return; }
        }

        // Bottom
        if(bi >= ti)
        {
            proceed = 1;
            i = bi , j = bjs;

            while (j > bje) { printf("%d ",matrix[i][j--]); } 
        }

        // Left
        if(lj <= rj)
        {
            proceed = 1;
            i = lis , j = lj;
            
            while (i > lie) { printf("%d ",matrix[i--][j]); }
        }

        ti++; tjs++; tje--; // top
        rj--; ris++; rie--; // right
        bi--; bjs--; bje++; // bottom
        lj++; lis--; lie++; // left
    }
}

/* Complete corner cases list
3 3
1 2 3 4 5 6 7 8 9

7 3
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21

4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

10 2
9 54 33 58 88 45 57 9 95 98 14 53 46 65 71 54 52 2 77 67

Input:
4 3
49 83 8 61 20 72 6 8 54 74 86 24

Its Correct output is:
49 83 8 72 54 24 86 74 6 61 20 8

And Your Code's output is:
49 83 8 72 54 24 86 74 6 61 20


Input:
7 3
21 26 73 22 72 0 0 90 43 33 46 29 57 32 74 34 95 41 25 74 67

Its Correct output is:
21 26 73 0 43 29 74 41 67 74 25 34 57 33 0 22 72 90 46 32 95

And Your Code's output is:
21 26 73 0 43 29 74 41 67 74 25 34 57 33 0 22 72 95 32 46 90

Input:
2 7
60 82 67 71 65 75 19 6 27 92 99 29 27 39

Its Correct output is:
60 82 67 71 65 75 19 39 27 29 99 92 27 6

And Your Code's output is:
60 82 67 71 65 75 19 39 27 29 99 92 27 6 0

*/
