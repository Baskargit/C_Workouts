
#include <stdio.h>
#include <stdlib.h>

void copystrings(char *s1,char *s2,char *dest);

struct number
{
    int originalnum;
    int convertednum;
};

int main()
{
    int n;
    scanf("%d",&n);

    struct number *numbers[n];
    int totalsum = 0;

    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d",&temp);

        struct number *numptr = (struct number *)malloc(sizeof(struct number));
        numptr->originalnum = temp;

        if (temp < 10) {
            switch (temp)
            {
                case 1:
                        numptr->convertednum = 111;
                        break;
                case 2:
                        numptr->convertednum = 222;
                        break;
                case 3:
                        numptr->convertednum = 333;
                        break;
                case 4:
                        numptr->convertednum = 444;
                        break;
                case 5:
                        numptr->convertednum = 555;
                        break;
                case 6:
                        numptr->convertednum = 666;
                        break;
                case 7:
                        numptr->convertednum = 777;
                        break;
                case 8:
                        numptr->convertednum = 888;
                        break;
                case 9:
                        numptr->convertednum = 999;
                        break;
                
                default:
                        numptr->convertednum = temp;
                        break;
            }
            // numptr->convertednum = temp * 100;
        }  else if(temp < 100){
            numptr->convertednum = temp * 10;
        } else {
            numptr->convertednum = temp;
        }

        numbers[i] = numptr;
        totalsum += temp;
    }

    // Sort based on the convertednum

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(numbers[j]->convertednum > numbers[i]->convertednum) 
            {
                struct number *temp = numbers[j];
                numbers[j] = numbers[i];
                numbers[i] = temp;
            }
        }
    }

    // Print the sorted result
    for (int i = 0; i < n; i++)
    {
        printf("%d ",numbers[i]->originalnum);
    }
    printf("\n");

    // check for equality in i+1 position

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(numbers[j]->convertednum == numbers[i]->convertednum) 
            {
                char n1[5],n2[5],n3[10],n4[10];

                sprintf(n1,"%d",numbers[i]->originalnum);
                sprintf(n2,"%d",numbers[j]->originalnum);

                copystrings(n1,n2,n3);
                copystrings(n2,n1,n4);
                
                int n3num,n4num;
                n3num = atoi(n3);
                n4num = atoi(n4);

                if(n4num > n3num) {
                    struct number *temp = numbers[j];
                    numbers[j] = numbers[i];
                    numbers[i] = temp;
                }

                break;
            }
        }
        
    }
    
    // Print the largest num
    if (totalsum > 0)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d",numbers[i]->originalnum);
        }
        printf("\n");
    } else {
        printf("0\n");
    }
    
    return 0;
}

void copystrings(char *s1,char *s2,char *dest)
{
    int destcount = 0;

    int k = 0;
    while (s1[k] != '\0')
    {
        dest[destcount++] = s1[k];
        k++;
    }

    k=0;
    while (s2[k] != '\0')
    {
        dest[destcount++] = s2[k];
        k++;
    }

    dest[destcount] = '\0';
}

/*
Input:
29
138 359 178 398 295 905 610 232 746 176 636 299 143 400 969 413 261 558 595 9 396 969 114 531 7 963 943 366 83

Its Correct output is:
9969969963943905837746636610595558531413400398396366359299295261232178176143138114

And Your Code's output is:
9699699639439059837467636610595558531413400398396366359299295261232178176143138114

Input:
86
624 421 145 969 736 916 626 535 43 12 680 153 245 296 819 397 693 816 992 34 670 398 554 548 826 211 663 212 809 378 762 626 336 869 996 777 768 440 875 332 557 302 873 561 95 985 756 790 408 16 194 770 681 456 856 507 964 503 677 109 250 332 845 639 809 998 652 850 204 732 532 15 420 776 10 181 930 224 55 261 738 546 318 526 201 257

Its Correct output is:
9989969929859699649593091687587386985685084582681981680980979077777677076876275673873673269368168067767066365263962662662456155755554548546535532526507503456440434214204083983973783433633233231830229626125725024522421221120420119418116153151451210910

And Your Code's output is:
9989969929859699649593091687587386985685084582681981680980979077777677076876275673873673269368168067767066365263962662662456155755455548546535532526507503456440434214204083983973783433633233231830229626125725024522421221120420119418116153151451210910

*/