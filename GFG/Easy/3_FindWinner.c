// https://practice.geeksforgeeks.org/problems/find-winner-of-the-game-of-nim/0

#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    printf("%s\n",(n % 2) ? "Player B" : "Player A");
    return 0;
}
