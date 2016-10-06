#include <stdio.h>

int main()
{
    char passwd[6];
    int i = 0;
    printf("Input your password:\n");
    for(i = 0; i < 6; i++)
    {
        
        while((passwd[i] = getchar()) < '0' || passwd[i] > '9') 
        {
            printf("error\n");
            while(getchar() != '\n');
        }
        while(getchar() != '\n');
        printf("%c,you have enter %d-bits number\n", passwd[i], i+1);
    }

}
