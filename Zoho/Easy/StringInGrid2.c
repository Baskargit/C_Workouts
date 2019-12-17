// Search in 4 directions but direction need not be in straight or diagonal
// horizontally left right and vertically top and bottom

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void setTraversebit(int m,int n,int traversebits[m][n]);

int main()
{
    // int m = 3,n = 13;
    // char grid[][13] = {"GEEKSFORGEEKS",
    //                    "GEEKSQUIZGEEK",
    //                    "IDEQAPRACTICE"
    //                    };

    // int m = 3,n = 4;
    // char grid[][5] = { "ABCE",
    //                    "SFCS",
    //                    "ADXZ"
    //                    };

    int m = 4,n = 4;
    char grid[][5] = { "axmy",
                       "bgdf",
                       "xeet",
                       "raks"
                       };

    char searchfor[] = "deek";
    int searchforlength = strlen(searchfor);

    // Print Matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ",grid[i][j]);
        }
        printf("\n");
    }

    int x[] = {-1,0,1,0};
    int y[] = {0,1,0,-1};

    // Keep track of visited letters
    int traversebits[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(grid[i][j] == searchfor[0]) 
            {
                setTraversebit(m,n,traversebits);
                traversebits[i][j] = 1;

                int tempi = i, tempj = j;
                bool isfound = (searchforlength > 1) ? false : true;
                bool proceed = false;

                // Iterate through string
                for (int l = 1; l < searchforlength; l++)
                {
                    // Search in 4 directions
                    for (int k = 0; k < sizeof(x)/sizeof(int); k++)
                    {
                        if ((tempi + x[k] >= 0 && tempi + x[k] < m) && (tempj + y[k] >= 0 && tempj + y[k] < n))
                        {
                            if (traversebits[tempi + x[k]][tempj + y[k]] == 0 && grid[tempi + x[k]][tempj + y[k]] == searchfor[l])
                            {
                                // letter found search for next letter
                                tempi = tempi + x[k];
                                tempj = tempj + y[k];
                                proceed = true;
                                isfound = true;

                                // set traversed bits
                                traversebits[tempi][tempj] = 1;
                                break;
                            } else {
                                isfound = false;
                                proceed = false;
                            }  
                        }
                    }
                    
                    if (!proceed) {
                        isfound = false;
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

void setTraversebit(int m,int n,int traversebits[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            traversebits[i][j] = 0;
        }
    }
}