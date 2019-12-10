/*
Sample:

Array : 
{2, 3, 7, ­1, 8, 5, 11} 
   
Output: 
{2­>3, 3­>5, 7­>8, ­1­>2, 8­>11, 5­>7, 11­>} 

*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n];
    int copiedarr[n];
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d",&temp);
        arr[i] = temp;
        copiedarr[i] = temp;
    }

    // Bubble sort
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(copiedarr[j] < copiedarr[i])
            {
                int temp = copiedarr[j];
                copiedarr[j] = copiedarr[i];
                copiedarr[i] = temp;
            }    
        }   
    }

    printf("\n");

    // print next greater
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(copiedarr[j] == arr[i] && copiedarr[j+1] != arr[i]) 
            {
                if(j != n - 1)
                {
                    printf("%d ",copiedarr[j+1]);
                    break;
                }
                else
                {
                    printf("_ ");
                }
            }
        }
    }
    
    printf("\n");
    
    return 0;
}

/*
Corner case:
If duplicate num exists then (j+1) for inequality copiedarr[j+1] != arr[i]
arr[]
1 38 38 40 39
copiedarr[]
1 38 38 39 40

*/

/*
Input:
100
795 792 224 713 278 869 982 698 202 227 234 349 781 181 274 690 628 38 582 508 471 414 748 182 38 706 433 703 77 119 758 648 936 760 704 253 105 717 426 16 869 699 906 116 911 892 741 91 31 489 936 793 282 608 597 597 242 436 544 399 578 136 409 486 0 117 945 5 972 897 43 442 677 626 667 313 402 39 87 777 303 1000 418 667 23 243 885 328 5 843 836 730 831 466 796 294 41 718 918 283

Its Correct output is:
796 793 227 717 282 885 1000 699 224 234 242 399 792 182 278 698 648 "39" 597 544 486 418 758 202 "39" 713 436 704 87 136 760 667 945 777 706 274 116 718 433 23 885 703 911 117 918 897 748 105 38 508 945 795 283 626 "608" "608" 243 442 578 402 582 181 414 489 5 119 972 "16" 982 906 77 466 690 628 677 328 409 41 91 781 313 _ 426 677 31 253 892 349 "16" 869 843 741 836 471 831 303 43 730 936 294

And Your Code's output is:
796 793 227 717 282 869 1000 699 224 234 242 399 792 182 278 698 648 "38" 597 544 486 418 758 202 "38" 713 436 704 87 136 760 667 936 777 706 274 116 718 433 23 869 703 911 117 918 897 748 105 38 508 936 795 283 626 "597" "597" 243 442 578 402 582 181 414 489 5 119 972 "5" 982 906 77 466 690 628 667 328 409 41 91 781 313 _ 426 667 31 253 892 349 "5" 869 843 741 836 471 831 303 43 730 936 294

*/
