/*
6. Cricket Scores
Given a timeline of scores, find the individual scores of player 1 and player 2 and Extras
W – Wide N – No Ball . – Dot Ball
Consider the game starts from player 1
I/P:

1 . 2 . 4 3 6 W 1 . N . 2 1
O/P:

P1 – 8
P2 – 12
Extras – 2
*/

#include <stdio.h>

int main()
{
    char scorecard[] = "1 . 2 . 4 3 6 W 1 . N . 2 1";

    int player1 = 0;
    int player2 = 0;
    int extras = 0;

    int *playerpointer = &player1;
    int i = 0;

    while (scorecard[i] != '\0')
    {
        if (scorecard[i] >= '0' && scorecard[i] <= '9') 
        {
            int score = scorecard[i] - '0';

            if (score != 0 && score % 2 == 0) {
                // no change
                *playerpointer += score;
            }  else {
                // non-strike become striker
                *playerpointer += score;
                playerpointer = (playerpointer == &player1) ? &player2 : &player1;
            }
        } else if(scorecard[i] == 'W' || scorecard[i] == 'N') {
            extras += 1;
        }

        i++;  
    }

    printf("P1 - %d\nP2 - %d\nExtras - %d\n",player1,player2,extras);
    
    return 0;
}
