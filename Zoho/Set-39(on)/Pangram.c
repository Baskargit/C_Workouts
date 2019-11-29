#include <stdio.h>

int main()
{
    char string[] = "abc defGhi JklmnOP QRStuv wxyz";

    int i = 0;
    int pangramdigit = 351;
    int result = 0;

    while (string[i] != '\0') 
    {
        if (string[i] >= 'a' && string[i] <= 'z' || string[i] >= 'A' && string[i] <= 'Z') 
        {
            if (string[i] >= 'a') {
                result += string[i] - 'a' + 1;
            } else {
                result += ((string[i] - 'A') + 'a' - 'a' + 1);
            }
        }
        i++;
    }
    printf("%d\n",result);

    printf("%s\n",(result == pangramdigit) ? "TRUE" : "NO");    
    return 0;
}
