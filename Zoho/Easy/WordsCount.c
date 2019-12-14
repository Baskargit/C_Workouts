#include<stdio.h>

int main()
{
	int testCaseCount;
    scanf("%d",&testCaseCount);
    
    for(int count=0; count<testCaseCount; count++)
    {
        char str[100];
        scanf("%s",str);
        
        int wordscount = (str[0] != '\0') ? 1 : 0;
        
        int i = 0;
        while(str[i] != '\0')
        {
            if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            {
                wordscount = (str[i+1] != '\0' && str[i+1] != ' ' && str[i+1] != '\t' && str[i+1] != '\n')
                                ? wordscount + 1
                                : wordscount;
                printf("%c %c",str[i],str[i+1]);
            }
            i++;
            printf("i = %d\n",i);
        }
        
        printf("%d\n",wordscount);
    }
    
	return 0;
}



/*
2
\t \n \t \n asd  \tnhy \nhgf \twerdsff      \tdfd\nsgsgb   hg
iwzcflsnqcxtm iidrblkiwcwaxmngfycecjr xjyuemjmuoevzqgxscxrqnxvlcbnlujidhehvpwpecmfssfnwe
*/