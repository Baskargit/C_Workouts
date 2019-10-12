#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    long int n;
    printf("Enter a number to check whether it is a prime or not ? \n");

    scanf("%ld",&n);
    printf("%s",(n > 0)
                ? (n == 1) 
                    ? "1 is not Prime by definition\n"
                    :  (n == 2)
                        ? "Prime number\n"
                        : (n % 2 != 0) ? "Prime number\n" : "Composite number\n"
                : "Not a valid number\n");
    return 0;
}
