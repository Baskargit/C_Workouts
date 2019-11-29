#include <stdio.h>
#include <string.h>

void horizontal(int row,int col,char arr[][col],int currentrow,int currentcol,char *searchfor,int strlength);
void vertical(int row,int col,char arr[][col],int currentrow,int currentcol,char *searchfor,int strlength);
void diagonal(int row,int col,char arr[][col],int currentrow,int currentcol,char *searchfor,int strlength);

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    
    getchar();
    char arr[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%c",&arr[i][j]);
        }
    }
    
    getchar();
    char searchfor[101];
    scanf("%[^\n]s",searchfor);

    int length = strlen(searchfor);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == searchfor[0])
            {
                // Horizontal
                horizontal(m,n,arr,i,j,searchfor,length);

                // Vertical
                vertical(m,n,arr,i,j,searchfor,length);

                // Diagonal
                diagonal(m,n,arr,i,j,searchfor,length);
            }   
        }    
    }

    printf("\n");
    
    return 0;
}

void diagonal(int row,int col,char arr[][col],int currentrow,int currentcol,char *searchfor,int strlength)
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
        printf("%d %d,",currentrow,currentcol);
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
        printf("%d %d,",currentrow,currentcol);
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
        printf("%d %d,",currentrow,currentcol);
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
        printf("%d %d,",currentrow,currentcol);
    }

}

void horizontal(int row,int col,char arr[][col],int currentrow,int currentcol,char *searchfor,int strlength)
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
        printf("%d %d,",currentrow,currentcol);
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
        printf("%d %d,",currentrow,currentcol);
    }
    
}

void vertical(int row,int col,char arr[][col],int currentrow,int currentcol,char *searchfor,int strlength)
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
        printf("%d %d,",currentrow,currentcol);
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
        printf("%d %d,",currentrow,currentcol);
    }
}