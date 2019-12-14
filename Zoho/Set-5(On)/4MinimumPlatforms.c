// 7:18
// https://practice.geeksforgeeks.org/problems/minimum-platforms/0
// https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
// https://youtu.be/GmpyAMpjpUY
// Not solved 
// incorrect logic

#include <stdio.h>
#include <stdlib.h>

struct Train
{
    int arrivalhours;
    int arrivalminutes;
    int departurehours;
    int departureminutes;
};

int main()
{
    int n;
    scanf("%d",&n);

    struct Train *trains[n];

    // Get Arrival timings
    for (int i = 0; i < n; i++)
    {
        getchar();
        struct Train *train = (struct Train *)malloc(sizeof(struct Train));

        char buffer[3];

        scanf("%c%c",&buffer[0],&buffer[1]);
        buffer[2] = '\0';
        train->arrivalhours = atoi(buffer);

        scanf("%c%c",&buffer[0],&buffer[1]);
        buffer[2] = '\0';
        train->arrivalminutes = atoi(buffer);

        trains[i] = train;
    }

    // Get Departure timings
    for (int i = 0; i < n; i++)
    {
        getchar();
        char buffer[2];

        scanf("%c%c",&buffer[0],&buffer[1]);
        buffer[2] = '\0';
        trains[i]->departurehours = atoi(buffer);

        scanf("%c%c",&buffer[0],&buffer[1]);
        buffer[2] = '\0';
        trains[i]->departureminutes = atoi(buffer);
    }

    // Print
    for (int i = 0; i < n; i++)
    {
        printf("Arr : %d:%d Dep : %d:%d\n",trains[i]->arrivalhours,trains[i]->arrivalminutes,trains[i]->departurehours,trains[i]->departureminutes);
    }

    // Sort based on arrivial time
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (trains[j]->arrivalhours < trains[i]->arrivalhours)
            {
                struct Train *temp = trains[j];
                trains[j] = trains[i];
                trains[i] = temp;
            }
        }
    }

    // Sort based on arrivial minutes
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if ((trains[j]->arrivalhours == trains[i]->arrivalhours) && (trains[j]->arrivalminutes < trains[i]->arrivalminutes))
            {
                struct Train *temp = trains[j];
                trains[j] = trains[i];
                trains[i] = temp;
            }
        }
    }

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Arr : %d:%d Dep : %d:%d\n",trains[i]->arrivalhours,trains[i]->arrivalminutes,trains[i]->departurehours,trains[i]->departureminutes);
    }
    
    // Calculate platformsneeded
    int platformsneeded = 0;
    for (int i = 0; i < n; i++)
    {
        int currentplatformneed = 1;

        for (int j = i+1; j < n; j++)
        {
            if ((trains[j]->arrivalhours >= trains[i]->arrivalhours && trains[j]->arrivalminutes >= trains[i]->arrivalminutes) && 
                (trains[j]->departurehours <= trains[i]->departurehours && trains[j]->departureminutes <= trains[i]->departureminutes))
            {
                currentplatformneed++;
            }
        }

        printf("currentplatformneed : %d\n",currentplatformneed);
        platformsneeded = (currentplatformneed > platformsneeded) ? currentplatformneed : platformsneeded;
    }
    
    printf("%d\n",platformsneeded);
    return 0;
}

/*
6
0900 0940 0950 1100 1500 1800
0910 1200 1120 1130 1900 2000

3
0900 1100 1235
1000 1200 1240

51
531 1927 815 521 914 99 1541 434 536 143 1850 1732 1114 1145 2337 18 128 1353 041 1058 1817 2020 109 2155 1453 64 740 337 1242 1045 522 2154 256 2251 1338 314 2133 1054 1242 148 1957 1059 2126 2137 1019 160 554 2029 2354 723 1343
015 85 93 209 557 1128 186 1824 031 1229 214 1443 523 1252 2353 252 1855 1231 1712 1838 187 2258 2119 018 43 1244 1152 1034 126 736 73 1028 1742 1017 111 1421 1549 1239 1250 223 1641 97 112 1622 030 235 233 159 202 848 720

35
0635 1032 0632 0941 1141 1509 1359 0128 0123 0626 0313 0350 0853 1551 0504 0123 0357 1500 0334 1315 0131 1008 0303 0926 0907 0932 0452 0127 0704 1854 1718 1924 1337 0623 0720
1202 2100 2151 0941 1751 1549 1411 0949 1500 0647 2105 1350 1552 2300 2022 1238 2013 1543 2300 1332 2125 1300 2000 0941 0924 1030 0800 2010 0755 1857 1829 2335 1348 1700 1500

Its Correct output is:
18
And Your Code's output is:
17

*/