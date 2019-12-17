// Non-Zig_Zag version 
// Search in all 8 fixed directions

// Accepcted Soln
// 0.01 Seconds of execution time

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    // int m = 3,n = 13;
    // char grid[][13] = {"GEEKSFORGEEKS",
    //                    "GEEKSQUIZGEEK",
    //                    "IDEQAPRACTICE"
    //                    };

    int m = 3,n = 4;
    char grid[][5] = { "ABCE",
                       "SFCS",
                       "ADXZ"
                       };

    char searchfor[] = "CB";
    int searchforlength = strlen(searchfor);

    // int m,n;
    // scanf("%d%d",&m,&n);
    
    // getchar();
    // char grid[m][n];
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         scanf("%c ",&grid[i][j]);
    //     }
    // }
    
    // char searchfor[101];
    // scanf("%s",searchfor);
    // printf("Searchfor : %s\n\n",searchfor);

    // int searchforlength = strlen(searchfor);
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ",grid[i][j]);
        }
        printf("\n");
    }

    int x[] = {-1,-1,0,1,1,1,0,-1};
    int y[] = {0,1,1,1,0,-1,-1,-1};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(grid[i][j] == searchfor[0]) 
            {
                bool isfound = (searchforlength > 1) ? false : true;
                int tempi = i, tempj = j;
                bool startagain = true;

                // Search in all 8 directions
                for (int l = 0; l < sizeof(x)/sizeof(int); l++)
                {
                    tempi = i, tempj = j;

                    if (startagain)
                    {
                        for (int k = 1; k < searchforlength; k++)
                        {
                            if ((tempi + x[l] >= 0 && tempi + x[l] < m) && (tempj + y[l] >= 0 && tempj + y[l] < n))
                            {
                                if(grid[tempi + x[l]][tempj + y[l]] == searchfor[k]) 
                                {
                                    // If same ,start searching in a fixed direction
                                    tempi = tempi + x[l];
                                    tempj = tempj + y[l];
                                    startagain = false;
                                    isfound = true;
                                } else {
                                    // Direction not matched (change the co-ordinates)
                                    startagain = true;
                                    isfound = false;
                                    break;
                                }
                            } else {
                                // Direction not matched (change the co-ordinates)
                                startagain = true;
                                isfound = false;
                                break;
                            }
                        }
                    } else {
                        // If no need to start again Match found
                        isfound = true;
                        break;
                    }
                }
                
                if(isfound) {
                    printf("%d %d, \n",i,j);
                }
            }
        } 
    }
    
    return 0;
}

/*
Input:
10 17
i k e n h a h i a i c i f f c n k m h a h j b h n o g e o i h h d l f c d e k l e e l b k o g m d n m k h f c m e b i d b i c l l o o h k b d g n o h a f o e j e b e e n o b c a c m b k g e g f d f h m i n c a m j m l n g i o d m m c f g j h k c j b g i n c n f o h k i o h c l l a k e g n b k a g i j g d l a e c i j l h g c g b k f a e i
ed

Its Correct output is:
2 3, 2 7, 4 12, 9 15,

And Your Code's output is:
2 3, 2 7, 4 12,

Input:
6 11
b h b o n h g h f e n e e c o m d a k o l e e b j i l e m m m g l n f b g d a l o o h k i n h m n k d c o i k a b g e f d i l h h j
fe

Its Correct output is:
0 8, 3 1, 5 4,

And Your Code's output is:
0 8, 5 4,

Input:  grid[][] = {"GEEKSFORGEEKS",
                    "GEEKSQUIZGEEK",
                    "IDEQAPRACTICE"};
        word = "GEEKS"

Output: pattern found at 0, 0
        pattern found at 0, 8
        pattern found at 1, 0

Input:  grid[][] = {"GEEKSFORGEEKS",
                    "GEEKSQUIZGEEK",
                    "IDEQAPRACTICE"};
        word = "EEE"

Output: pattern found at 0, 2
        pattern found at 0, 10
        pattern found at 2, 2
        pattern found at 2, 12
*/