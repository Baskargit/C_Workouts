//6:51
// https://practice.geeksforgeeks.org/problems/lets-play/0
// https://www.geeksforgeeks.org/array-rotation/


// #include<stdio.h>

// int main()
// {
//     int n,m;
//     scanf("%d %d",&n,&m);

//     int matrix[n][m];
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             scanf("%d",&matrix[i][j]);
//         }
//     }

//     int x;
//     scanf("%d",&x);

//     int rotatedmatrix[n][m];

//     for (int i = 0; i < n; i++)
//     {
//         int pos = 0;

//         if (i % 2 == 0) // left
//         {
//             // first loop
//             for (int j = x; j < m; j++)
//             {
//                 rotatedmatrix[i][pos++] = matrix[i][j];
//             }

//             // Second loop
//             for (int j = 0; j < x; j++)
//             {
//                 rotatedmatrix[i][pos++] = matrix[i][j];
//             } 
//         }
//         else // Rigth
//         {
//             // first loop
//             for (int j = (m - x + 1); j < m; j++)
//             {
//                 rotatedmatrix[i][pos++] = matrix[i][j];
//             }

//             // Second loop
//             for (int j = 0; j <= m - x; j++)
//             {
//                 rotatedmatrix[i][pos++] = matrix[i][j];
//             }   
//         }   
//     }

//     //print
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             printf("%d ",rotatedmatrix[i][i]);
//         }
//         printf("\n");
//     }

//     // Check Matrix
//     int flag = 1;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (rotatedmatrix[i][j] != matrix[i][j])
//             {
//                 return 0;
//             }
//         }
//     }
    
//     return flag;
//     return 0;
// }


#include<stdio.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    int matrix[n][m],rotatedmatrix[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp;
            scanf("%d ",&temp);

            matrix[i][j] = temp;
            rotatedmatrix[i][j] = temp;
        }
    }

    int x;
    scanf("%d",&x);

    //print
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ",rotatedmatrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        int tempx = x;

        if (i % 2 == 0) // left
        {
            while (tempx--)
            {
                int firstelement = rotatedmatrix[i][0];
                int pos = 0;

                for (int j = 1; j < m; j++)
                {
                    rotatedmatrix[i][pos++] = rotatedmatrix[i][j];
                }
                rotatedmatrix[i][pos] = firstelement;
            }
        }
        else // right
        {
            while (tempx--)
            {
                int lastelement = rotatedmatrix[i][m-1];
                int temp = rotatedmatrix[i][0];
                int pos = 0;
                rotatedmatrix[i][pos++] = lastelement;

                for (int j = 1; j < m; j++)
                {
                    int temp1 = rotatedmatrix[i][j];
                    rotatedmatrix[i][pos++] = temp;
                    temp = temp1;
                } 
            }
        }
        
    }

    //print
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ",rotatedmatrix[i][j]);
        }
        printf("\n");
    }

    // Check Matrix
    int flag = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (rotatedmatrix[i][j] != matrix[i][j])
            {
                flag = 0;
                i = n;
                break;
            }
        }
    }
    
    printf("%d\n",flag);
    return 0;
}

/*
1 7
1 2 3 4 5 6 7
1

Input:
4 3
5 9 8 8 4 5 5 10 10 7 10 1
6

Its Correct output is:
1

And Your Code's output is:
0

*/
