/*
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

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    int m = 3,n = 13;
    char grid[][13] = {"GEEKSFORGEEKS",
                       "GEEKSQUIZGEEK",
                       "IDEQAPRACTICE"
                       };

    // int m = 3,n = 4;
    // char grid[][13] = {"ABCE",
    //                    "SFCS",
    //                    "ADEE"
    //                    };

    char searchfor[] = "EEE";
    int searchforlength = strlen(searchfor);

    int x[] = {0,1,1,1,0,-1,-1,1};
    int y[] = {1,1,0,-1,-1,-1,0,-1};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(grid[i][j] == searchfor[0]) 
            {
                bool isfound = true;
                int matchlength = 1;

                int tempi = i, tempj = j;
                bool firstime = true;
                int inciby,incjby;

                // Start from 2 letter of 'searchfor'
                for (int k = 1; k < searchforlength; k++)
                {
                    bool ismatchfound = false;

                    // Search in all 8 directions
                    for (int l = 0; l < 8; l++)
                    {
                        if((tempi + x[l] >= 0 && tempi + x[l] < m && tempj + y[l] >= 0 && tempj + y[l] < n)) 
                        {
                            if(firstime && grid[tempi + x[l]][tempj + y[l]] == searchfor[k]) 
                            {
                                // If Set ,the searching starts in fixed direction
                                inciby = x[l];
                                incjby = y[l];
                                tempi = tempi + x[l];
                                tempj = tempj + y[l];
                                ismatchfound = true;
                                matchlength++;
                                firstime = false;
                                break;
                            }
                            else if(!firstime && grid[tempi + inciby][tempj + incjby] == searchfor[k]) {
                                tempi = tempi + inciby;
                                tempj = tempj + incjby;
                                ismatchfound = true;
                                matchlength++;
                                break;
                            }
                            
                        }
                    }

                    if(!ismatchfound) {
                        isfound = false;
                        break;
                    }   
                }

                if(isfound && searchforlength == matchlength) {
                    printf("%d %d\n",i,j);
                }
            }
        }
        
    }
    
    
    return 0;
}
