#include<stdio.h>

void getNotesCount(int n,int amount,int notes[],int pos);

int main()
{
    int amount = 800;
    int notes[] = {2000,500,200,100,50,20,10,5,1};

    getNotesCount(sizeof(notes)/sizeof(int),amount,notes,0);
    return 0;
}

void getNotesCount(int n,int amount,int notes[],int pos)
{
    if (pos < n - 1)
    {
        printf("%d : %d\n",notes[pos],amount/notes[pos]);
        return getNotesCount(n,(amount/notes[pos] > 0) ? amount/notes[pos] : amount,notes,++pos);
    }

    printf("%d : %d\n",notes[pos],amount * notes[pos]);
    return;
}
