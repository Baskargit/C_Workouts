#include <stdio.h>
#include <stdlib.h>

struct number
{
    int num;
    int frequency;
};

int main()
{
    int n;
    scanf("%d",&n);

    struct number *numbers[n];
    int numberscounter = 0;

    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d",&temp);

        int ispresent = 0;

        for (int j = 0; j < numberscounter; j++)
        {
            if(numbers[j]->num == temp) {
                ispresent = 1;
                numbers[j]->frequency = numbers[j]->frequency + 1;
                break; 
            }
        }

        if(ispresent == 0) {
            struct number *num =  (struct number *)malloc(sizeof(struct number));
            num->num = temp;
            num->frequency = 1;

            numbers[numberscounter++] = num;
        }
    }

    // Sort the numbers based on frequency
    for (int i = 0; i < numberscounter; i++)
    {
        for (int j = i+1; j < numberscounter; j++)
        {
            if(numbers[j]->frequency > numbers[i]->frequency) 
            {
                struct number *temp = numbers[j];
                numbers[j] = numbers[i];
                numbers[i] = temp;
            }
        }
    }

    //print
    // for (int i = 0; i < numberscounter; i++)
    // {
    //     printf("%d  freq %d\n",numbers[i]->num,numbers[i]->frequency);
    // }

    // Sort if there any same frequency exists
    for (int i = 0; i < numberscounter; i++)
    {
        for(int j = i+1; j < numberscounter; j++) 
        {
            if((numbers[j]->frequency == numbers[i]->frequency) && (numbers[j]->num < numbers[i]->num)) {
                struct number *temp = numbers[j];
                numbers[j] = numbers[i];
                numbers[i] = temp;
            }
        }
    }

    // print the numbers
    for (int i = 0; i < numberscounter; i++)
    {
        for (int j = 1; j <= numbers[i]->frequency; j++)
        {
            printf("%d ",numbers[i]->num);
        }
    }

    printf("\n");
    
    return 0;
}

/*
Input:
109
19 14 15 8 1 3 6 12 5 7 17 3 6 8 2 8 18 10 15 7 8 20 8 13 18 9 2 1 1 10 11 8 14 20 14 1 2 15 13 21 6 7 11 1 8 9 18 19 18 4 4 19 9 12 17 13 21 14 13 12 4 13 1 12 18 21 15 5 4 13 7 3 3 18 19 4 21 17 11 3 15 7 5 13 14 17 19 21 2 8 13 20 11 11 2 2 13 16 2 7 3 21 10 9 13 11 9 12 5

Its Correct output is:
13 13 13 13 13 13 13 13 13 13 8 8 8 8 8 8 8 8 2 2 2 2 2 2 2 1 1 1 1 1 1 3 3 3 3 3 3 7 7 7 7 7 7 11 11 11 11 11 11 18 18 18 18 18 18 21 21 21 21 21 21 4 4 4 4 4 9 9 9 9 9 12 12 12 12 12 14 14 14 14 14 15 15 15 15 15 19 19 19 19 19 5 5 5 5 17 17 17 17 6 6 6 10 10 10 20 20 20 16

And Your Code's output is:
13 13 13 13 13 13 13 13 13 13 8 8 8 8 8 8 8 8 2 2 2 2 2 2 2 1 1 1 1 1 1 7 7 7 7 7 7 3 3 3 3 3 3 11 11 11 11 11 11 18 18 18 18 18 18 21 21 21 21 21 21 12 12 12 12 12 9 9 9 9 9 15 15 15 15 15 14 14 14 14 14 4 4 4 4 4 19 19 19 19 19 5 5 5 5 17 17 17 17 6 6 6 10 10 10 20 20 20 16


*/
