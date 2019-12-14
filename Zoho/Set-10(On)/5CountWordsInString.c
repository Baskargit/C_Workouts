#include<stdio.h>
#include<string.h>

int main()
{
    char str[] = "Jana gana mana adhinaayaka jaya hay Bhaaratha Bhaagya Vidhaata Punjab Sindhu Gujarat Maraatha Draavida Utkala Banga Vindhya Himaachala Yamuna Ganga Ucchala jaladhi taranga Tava Shubha naame jaage Tava shubha aashisha maage Gaahey tava jaya gaathaa Jana Gana Mangala Daayaka jaya hay Bhaaratha Bhaagya Vidhaata Jaya hay Jaya hay Jaya hay Jaya Jaya Jaya Jaya hay";
    
    // char str[] = "b";

    // convert all upper case to lower case

    int i = 0,wordcount = (str[0] != '\0') ? 1 : 0;
    while (str[i] != '\0')
    {
        if(str[i] >= 'A' && str[i] <= 'Z') 
        {
            str[i] = str[i] - 'A' + 'a';
        }
        i++;
        wordcount += (str[i] == ' ') ? 1 : 0;
    }

    int length = i;

    i = 0;
    char words[wordcount][length];
    int wordsposi = 0 ,wordsposj = 0;

    while (str[i] != '\0')
    {
        wordsposj = 0;
        
        // Copy words
        while (str[i] != '\0' && str[i] != ' ' && (words[wordsposi][wordsposj++] = str[i++]));
        words[wordsposi++][wordsposj] = '\0';

        i++;
        printf("%s ",words[wordsposi-1]);
    }
    printf("\n\n");

    int wordscount[wordsposi];

    for (int i = 0; i < wordsposi; i++)
    {
        wordscount[i] = 1;
        for (int j = i+1; j < wordsposi; j++)
        {
            if(strcmp(words[i],words[j]) == 0) 
            {
                words[j][0] = '\0';
                wordscount[i] += 1;
            }
        }
    }

    for (int i = 0; i < wordsposi; i++)
    {
        if(words[i][0] != '\0') 
        {
            printf("%s => %d\n",words[i],wordscount[i]);
        }
    }
    
    
    return 0;
}
