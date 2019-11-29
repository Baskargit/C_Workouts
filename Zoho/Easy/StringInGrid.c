#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool horizontal(int row,int col,char arr[][col],int currentrow,int currentcol,char *searchfor,int strlength,bool *flag);
bool vertical(int row,int col,char arr[][col],int currentrow,int currentcol,char *searchfor,int strlength,bool *flag);
bool diagonal(int row,int col,char arr[][col],int currentrow,int currentcol,char *searchfor,int strlength,bool *flag);

int main()
{
	int testCaseCount;
    scanf("%d",&testCaseCount);
    
    for(int count=0; count<testCaseCount; count++)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        
        getchar();
        char arr[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%c ",&arr[i][j]);
            }
        }

        char searchfor[101];
        scanf("%[^\n]s",searchfor);

        int length = strlen(searchfor);

        // print
        printf("\n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%c ",arr[i][j]);
            }
            printf("\n");
        }
        // printf("\nSearchfor :%s\n",searchfor);

        bool flag = false;

        if (length != 1) 
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (arr[i][j] == searchfor[0])
                    {
                        bool tempflag = false;
                        
                        // Horizontal
                        tempflag = horizontal(m,n,arr,i,j,searchfor,length,&flag);

                        // Vertical
                        if (!tempflag) {
                            tempflag = vertical(m,n,arr,i,j,searchfor,length,&flag);
                        }
                        
                        
                        // Diagonal
                        if (!tempflag) {
                            diagonal(m,n,arr,i,j,searchfor,length,&flag);
                        }
                        
                        
                    }   
                }
            }
        } else {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (arr[i][j] == searchfor[0]) {
                        printf("%d %d, ",i,j);
                        flag = 1;
                    }
                    
                }
            }
        }
        
        printf("%s",(flag) ? "\n" : "-1\n");
    }
    
	return 0;
}

bool diagonal(int row,int col,char arr[][col],int currentrow,int currentcol,char *searchfor,int strlength,bool *flag)
{
    char compare[strlength+1];
    int i=currentrow,j=currentcol;
    int counter = 0;

    // Diagonal up
    // left
    while ((j >= 0 && i >= 0) && counter < strlength)
    {
        compare[counter++] = arr[i--][j--];
    }
    compare[counter] = '\0';
    if (strcmp(searchfor,compare) == 0) {
        printf("%d %d, ",currentrow,currentcol);
        *flag = true;
        return true;
    }

    // right
    i=currentrow,j=currentcol;
    counter = 0;
    while ((j < col && i >= 0) && counter < strlength)
    {
        compare[counter++] = arr[i--][j++];
    }
    compare[counter] = '\0';
    if (strcmp(searchfor,compare) == 0) {
        printf("%d %d, ",currentrow,currentcol);
        *flag = true;
        return true;
    }

    // Diagonal down
    // left
    i=currentrow,j=currentcol;
    counter = 0;
    while ((j >= 0 && i < row) && counter < strlength)
    {
        compare[counter++] = arr[i++][j--];
    }
    compare[counter] = '\0';
    if (strcmp(searchfor,compare) == 0) {
        printf("%d %d, ",currentrow,currentcol);
        *flag = true;
        return true;
    }
    
    // right
    i=currentrow,j=currentcol;
    counter = 0;
    while ((j < col && i < row) && counter < strlength)
    {
        compare[counter++] = arr[i++][j++];
    }
    compare[counter] = '\0';
    if (strcmp(searchfor,compare) == 0) {
        printf("%d %d, ",currentrow,currentcol);
        *flag = true;
        return true;
    }

    return false;
}

bool horizontal(int row,int col,char arr[][col],int currentrow,int currentcol,char *searchfor,int strlength,bool *flag)
{
    char compare[strlength+1];

    int j = currentcol;
    int counter = 0;

    // left
    while (j >= 0 && counter < strlength)
    {
        compare[counter++] = arr[currentrow][j--];
    }
    compare[counter] = '\0';

    if (strcmp(searchfor,compare) == 0) {
        printf("%d %d, ",currentrow,currentcol);
        *flag = true;
        return true;
    }

    
    // right
    j = currentcol;
    counter = 0;

    while (j < col && counter < strlength)
    {
        compare[counter++] = arr[currentrow][j++];
    }
    compare[counter] = '\0';

    if (strcmp(searchfor,compare) == 0) {
        printf("%d %d, ",currentrow,currentcol);
        *flag = true;
        return true;
    }

    return false;
}

bool vertical(int row,int col,char arr[][col],int currentrow,int currentcol,char *searchfor,int strlength,bool *flag)
{
    char compare[strlength+1];

    int i = currentrow;
    int counter = 0;

    // up
    while (i >= 0 && counter < strlength)
    {
        compare[counter++] = arr[i--][currentcol];
    }
    compare[counter] = '\0';

    if (strcmp(searchfor,compare) == 0) {
        printf("%d %d, ",currentrow,currentcol);
        *flag = true;
        return true;
    }

    
    // down
    i = currentrow;
    counter = 0;

    while (i < row && counter < strlength)
    {
        compare[counter++] = arr[i++][currentcol];
    }
    compare[counter] = '\0';

    if (strcmp(searchfor,compare) == 0) {
        printf("%d %d, ",currentrow,currentcol);
        *flag = true;
        return true;
    }

    return false;
}