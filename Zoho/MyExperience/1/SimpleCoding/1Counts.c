#include<stdio.h>

int main()
{
    FILE *fileptr = fopen("1testfile.txt","r");
    char c = fgetc(fileptr);

    unsigned long long int lines,spaces,words,tabs;
    lines = spaces = tabs = words = 0;
    int state = 0; // 0 -> Out 1 -> In
    int counter = 0;

    while (c != EOF)
    {
        printf("%c",c);

        lines = (c == '\n') ? lines + 1 : lines;
        spaces = (c == ' ') ? spaces + 1 : spaces;
        tabs = (c == '\t') ? tabs + 1 : tabs;
        
        if (c == ' ' || c == '\t' || c == '.' || c == ',' || c == '\n')
        {
            state = 0;
        }
        else if(state == 0)
        {
            ++words;
            state = 1;
        }
        
        c = fgetc(fileptr);
        counter++;
    }
    fclose(fileptr);

    printf("\nWords : %llu\n",words);
    printf("Spaces : %llu\n",spaces);
    printf("Tabs : %llu\n",tabs);
    printf("Lines : %llu\n",(counter || spaces || words || tabs) ? lines + 1 : lines);
    
    return 0;
}
