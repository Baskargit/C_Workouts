#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 10;

    int *ptr = &a;

    printf("%p\n",ptr);
    printf("%p\n",&ptr);

    // Pointer to an array (sort)
    int b[5] = {2,5,1,4,3};
    for (int i = 0; i < 5; i++)
    {
        printf("&b[%d] => %p\n",i,&b[i]);
    }

    int *ptrb[5]; // Array of pointers
    printf("\nSizeof(*ptrb[5]) = %ld\n",sizeof(ptrb));

    for (int i = 0; i < 5; i++)
    {
        ptrb[i] = &b[i];
    }

    for (int i = 0; i < 5; i++)
    {
        printf("*ptrb[%d] => %p\n",i,&ptrb[i]);
    }

    // Bubble sort

    for (int i = 0; i < 5; i++)
    {
        for (int j = i+1; j < 5; j++)
        {
            if (**(ptrb+j) < **(ptrb+i))
            {
                int *temp = *(ptrb+j);
                *(ptrb+j) = *(ptrb+i);
                *(ptrb+i) = temp;              
            }
            
        }
        
    }

    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("*ptrb[%d] => %p ===> %d\n",i,*(ptrb+i),**(ptrb+i));
    }

    return 0;
}
