    // Non-decimal conversion

    #include<stdio.h>
    #include<string.h>

    void printHexvalue(int n,char binary[],char buffer[],int bufferpos);
    char getHexValue(char binary[]);

    int main()
    {
        char binary[] = "11111";
        char buffer[5] = {'0'}; // Initialize char '0' by default
        
        printHexvalue(sizeof(binary)/sizeof(char) - 2,binary,buffer,sizeof(buffer) - 2);
        printf("\n");
        return 0;
    }

    void printHexvalue(int n,char binary[],char buffer[],int bufferpos)
    {
        if (n >= 0)
        {
            if (bufferpos >= 0)
            {
                buffer[bufferpos] = binary[n];
                return printHexvalue(--n,binary,buffer,--bufferpos);
            }
            else
            {
                buffer[4] = '\0';
                char result = getHexValue(buffer);

                buffer[0] = '0';buffer[1] = '0';buffer[2] = '0';buffer[3] = '0';
                bufferpos = 3;
                printHexvalue(n,binary,buffer,bufferpos);
                
                printf("%c",result);
                return;
            }
        }
        
        printf("%c",getHexValue(buffer));
        return;
    }

char getHexValue(char binary[])
{
    if (strcmp(binary,"0000") == 0)
    {
        return '\0';
    }
    else if (strcmp(binary,"0001") == 0)
    {
        return '1';
    }
    else if (strcmp(binary,"0010") == 0)
    {
        return '2';
    }
    else if (strcmp(binary,"0011") == 0)
    {
        return '3';
    }
    else if (strcmp(binary,"0100") == 0)
    {
        return '4';
    }
    else if (strcmp(binary,"0101") == 0)
    {
        return '5';
    }
    else if (strcmp(binary,"0110") == 0)
    {
        return '6';
    }
    else if (strcmp(binary,"0111") == 0)
    {
        return '7';
    }
    else if (strcmp(binary,"1000") == 0)
    {
        return '8';
    }
    else if (strcmp(binary,"1001") == 0)
    {
        return '9';
    }
    else if (strcmp(binary,"1010") == 0)
    {
        return 'A';
    }
    else if (strcmp(binary,"1011") == 0)
    {
        return 'B';
    }
    else if (strcmp(binary,"1100") == 0)
    {
        return 'C';
    }
    else if (strcmp(binary,"1101") == 0)
    {
        return 'D';
    }
    else if (strcmp(binary,"1110") == 0)
    {
        return 'E';
    }
    else if (strcmp(binary,"1111") == 0)
    {
        return 'F';
    }
    else
    {
        return '\0';   
    }
}
