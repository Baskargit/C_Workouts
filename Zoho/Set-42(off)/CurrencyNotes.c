// https://www.geeksforgeeks.org/zoho-interview-experience-set-42off-campus/

#include <stdio.h>

// int main()
// {
//     int notes[] = {2000,500,200,100,50,20,10,5,1};
//     int noteCounts[sizeof(notes)/sizeof(int)];

//     int partitioned[50];
//     int counter = 0;

//     int money = 2456;

//     int tempmoney = money;
//     int multiplier = 1;
//     while (tempmoney != 0)
//     {
//         partitioned[counter++] = (tempmoney % 10) * multiplier;
//         multiplier *= 10;
//         tempmoney /= 10;
//     }

//     for (int i = counter - 1; i >= 0; i--)
//     {
//         printf("%d+",partitioned[i]);
//     }
//     printf("\n");

//     // Note Count
//     int notesCounter = 0;
//     int noteCountsCounter = 0;
//     for (int i = counter - 1; i >= 0; i--)
//     {
//         int multiplier = 1;
//         int tempValue = partitioned[i] * multiplier;

//         while (tempValue <= partitioned[i])
//         {
//             noteCounts[noteCountsCounter] = multiplier;
//             ++multiplier;
//             tempValue += (partitioned[i] * multiplier);
//         }
        
        
//     }
    
    
//     return 0;
// }

int main(int argc, char const *argv[])
{
    int notes[] = {2000,500,200,100,50,20,10,5,1};
    int noteCounts[] = {0,0,0,0,0,0,0,0,0};

    int money = 7894569;
    int tempmoney = money;

    for (int i = 0; i < sizeof(notes)/sizeof(int); i++)
    {
        int noteCount = tempmoney/notes[i];

        if (noteCount > 0) {
            noteCounts[i] = noteCount;
            tempmoney -= (notes[i] * noteCount);
        }   
    }

    for (int i = 0; i < sizeof(notes)/sizeof(int); i++)
    {
        if (noteCounts[i] > 0) {
            printf("%d : %d\n",notes[i],noteCounts[i]);
        }
    }
    
    return 0;
}
