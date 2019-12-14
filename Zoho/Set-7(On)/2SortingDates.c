// 2:00 -

#include <stdio.h>
#include <stdlib.h>

struct Date
{
    int year,month,date;
};

int main()
{
    int n;
    scanf("%d",&n);

    struct Date *dates[n];

    for (int i = 0; i < n; i++)
    {
        struct Date *date = (struct Date *)malloc(sizeof(struct Date));

        scanf("%d%d%d",&date->date,&date->month,&date->year);
        dates[i] = date;
    }

    // Sort based on year
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (dates[j]->year < dates[i]->year)
            {
                struct Date *temp = dates[j];
                dates[j] = dates[i];
                dates[i] = temp;
            }
        }
    }
    
    // Sort based on month
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (dates[j]->year == dates[i]->year && dates[j]->month < dates[i]->month)
            {
                struct Date *temp = dates[j];
                dates[j] = dates[i];
                dates[i] = temp;
            }
        }
    }

    // Sort based on date
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (dates[j]->year == dates[i]->year && dates[j]->month == dates[i]->month && dates[j]->date < dates[i]->date)
            {
                struct Date *temp = dates[j];
                dates[j] = dates[i];
                dates[i] = temp;
            }
        }
    }

    //Print the result
    printf("Sorted dates\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n",dates[i]->date,dates[i]->month,dates[i]->year);
    }
    
    return 0;
}

/*
Input:
       Date arr[] = {{20,  1, 2014},
                    {25,  3, 2010},
                    { 3, 12, 1676},
                    {18, 11, 1982},
                    {19,  4, 2015},
                    { 9,  7, 2015}}

Output:
      Date arr[] = {{ 3, 12, 1676},
                    {18, 11, 1982},
                    {25,  3, 2010},
                    {20,  1, 2014},
                    {19,  4, 2015},
                    { 9,  7, 2015}}

6
20  1 2014
25  3 2010
3 12 1676
18 11 1982
19  4 2015
9  7 2015
*/
