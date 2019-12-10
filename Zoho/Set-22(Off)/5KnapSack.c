// Not correct

#include <stdio.h>
#include <stdlib.h>

struct item
{
    int value;
    int weight;
};

int main()
{
    int n,maxcapacity;
    scanf("%d",&n);
    scanf("%d",&maxcapacity);

    struct item *items[n];
    int temp;
    // Get values
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&temp);

        struct item *item = (struct item *)malloc(sizeof(struct item));
        item->value = temp;

        items[i] = item;
    }

    // Get weights of n items
    int minweight = 0,minweightvalue = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&temp);
        items[i]->weight = temp;

        minweight = (i == 0) ? temp : minweight;
        minweightvalue = (i == 0) ? items[0]->value : minweightvalue;

        // minweight = (temp < minweight) ? temp : minweight;
        if(temp < minweight) 
        {
            minweight = temp;
            minweightvalue = items[i]->value;
        }

        if(temp > maxcapacity) {
            items[i] = NULL;
        }
    }

    // remove excess weights
    temp = 0;
    for (int i = 0; i < n; i++)
    {
        if(items[i] != NULL) 
        {
            items[temp++] = items[i];
        }
    }

    // set new limit
    n = temp;

    // Sort items based on values > to <
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(items[j]->weight < items[i]->weight)
            {
                struct item *temp = items[j];
                items[j] = items[i];
                items[i] = temp;
            }   
        }
    }

    printf("value ===> weight\n");
    for (int i = 0; i < n; i++)
    {
        printf("+%d",items[i]->value);
    }
    printf("\n");

    if(minweight <= maxcapacity) 
    {
        int maxvalue = 0;
        
        int i=0,j=0;
        while (i < n)
        {
            int weightsum = items[i]->weight;
            int currentsubsetvalue = items[i]->value;

            printf("%d ",weightsum);
            j = i + 1;
            while (j < n && weightsum + items[j]->weight <= maxcapacity)
            {
                weightsum += items[j]->weight;
                currentsubsetvalue += items[j]->value;
                j++;
                // printf("%d ",weightsum);
            }

            printf("%d\n",weightsum);
            maxvalue = (currentsubsetvalue > maxvalue) ? currentsubsetvalue : maxvalue;
            i++;
            // j = i;
        }

        printf("%d\n",maxvalue);
    }
    else 
    {
        // print the min weight index value
        printf("%d\n",minweightvalue);
    }
    
    
    return 0;
}

/*
Input:
58
41
57 95 13 29 1 99 34 77 61 23 24 70 73 88 33 61 43 5 41 63 8 67 20 72 98 59 46 58 64 94 97 70 46 81 42 7 1 52 20 54 81 3 73 78 81 11 41 45 18 94 24 82 9 19 59 48 2 72
83 84 85 76 13 87 2 23 33 82 79 100 88 85 91 78 83 44 4 50 11 68 90 88 73 83 46 16 7 35 76 31 40 49 65 2 18 47 55 38 75 58 86 77 96 94 82 92 10 86 54 49 65 44 77 22 81 52

Its Correct output is:
223

And Your Code's output is:
99

28
83
55 61 51 75 17 22 4 13 39 28 77 49 46 91 14 67 88 62 25 37 69 38 59 62 48 88 100 53 
96 16 34 53 88 6 50 26 76 10 8 4 37 18 73 54 30 31 97 2 28 24 2 30 79 77 33 86 

16
98
20 16 45 73 99 87 38 53 99 99 38 65 22 17 17 51 
31 21 78 53 18 66 61 4 11 65 16 99 87 91 44 23

*/

