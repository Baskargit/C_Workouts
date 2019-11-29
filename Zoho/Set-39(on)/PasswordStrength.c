#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    char password[] = "Qwertyiou";

    int lc = 0;
    int uc = 0;
    int num = 0;
    int schar = 0;

    int i = 0;

    while (password[i] != '\0') 
    {
        if (password[i] >= 'a' && password[i] <= 'z') {
            ++lc;
        } else if(password[i] >= 'A' && password[i] <= 'Z') {
            ++uc;
        } else if(password[i] >= '0' && password[i] <= '9') {
            ++num;
        } else {
            ++schar;
        }
        i++;
    }

    if (lc + uc + num + schar < 8) {
        printf("%s\n","Weak");
    } else if(uc < 1 && lc < 1) {
        printf("%s\n","Weak");
    } else if(num < 1) {
        printf("%s\n","Medium");
    } else if(schar < 1) {
        printf("%s\n","Good");
    } else {
        printf("%s\n","Strong");
    } 
    
    
    return 0;
}
