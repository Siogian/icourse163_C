#include <stdio.h>
#include <math.h>
   int main()
   {
     int n, i;
     printf("Input n:\n");
     scanf("%d", &n);
    //printf("%d", sqrt(n));
    if(n < 2)
    {
        printf("No!\n");
        goto EXIT;
    }
     for (i=2; i<=sqrt(n); i++)
     {
       if (n % i == 0)
       {
         printf("No!\n");
         goto EXIT;
       }
    }
    printf("Yes!\n");
    EXIT:
    return 0;
  }


