/*
Find minimum number of currency notes and values that sum to given amount

Input : 800
Output : Currency  Count 
         500 : 1
         200 : 1
         100 : 1

Input : 2456
Output : Currency  Count
         2000 : 1
         200 : 2
         50 : 1
         5 : 1
         1 : 1
*/

#include<stdio.h>

void getNotesCount(int n,unsigned long long int amount,int notes[],int pos);

int main()
{
    unsigned long long int amount = 19;
    int notes[] = {2000,500,200,100,50,20,10,5,1};

    getNotesCount(sizeof(notes)/sizeof(int),amount,notes,0);
    return 0;
}

void getNotesCount(int n,unsigned long long int amount,int notes[],int pos)
{
    if (pos < n - 1)
    {
        unsigned long long int notecount = amount/notes[pos];

        if (notecount > 0)
        {
            printf("%d : %llu\n",notes[pos],notecount);
            amount -= notecount * notes[pos];
        }
        
        return getNotesCount(n,amount,notes,++pos);
    }

    if (amount > 0)
    {
        printf("%d : %llu\n",notes[pos],amount * notes[pos]);    
    }
    
    return;
}
