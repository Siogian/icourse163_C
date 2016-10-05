#include <stdio.h>
int main()
{
    int sum = 0, m;
    printf("Input m:\n"); 
    scanf("%d", &m); 
    while(m != 0){    
        sum = sum + m;
        printf("sum = %d\n", sum);  
        printf("Input m:\n"); 
        scanf("%d", &m); 
    }
    return 0;
}


