/*
https://practice.geeksforgeeks.org/problems/tower-of-hanoi/0

*/

// Not completed

#include<stdio.h>
#include<stdlib.h>

struct Disc
{
    int weight;
};

unsigned int powof(int base,int power);
void insertDiscs(int n,struct Disc *peg1[n]);

int main()
{
    int n = 2;

    struct Disc *peg1[n+1];
    struct Disc *peg2[n+1];
    struct Disc *peg3[n+1];

    int peg1ptr,peg2ptr,peg3ptr;
    peg1ptr = 1;
    peg2ptr = peg3ptr = n + 1;

    unsigned int till = powof(2,n) - 1;

    for (unsigned int i = 1; i <= till; i++)
    {
        
    }
    
    return 0;
}

void insertDiscs(int n,struct Disc *peg1[n])
{
    for (int i = 1; i <= n; i++)
    {
        struct Disc *disc = (struct Disc *)malloc(sizeof(struct Disc));
        disc->weight = i;
        peg1[i] = disc;
    }
}

unsigned int powof(int base,int power)
{
    return (power) ? base * powof(base,power - 1) : 1 ;
}