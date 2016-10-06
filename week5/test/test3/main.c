#include <stdio.h>

int main()
{
    int odd = 0;
    int even = 0;
    int n;
    printf("Please enter the number:\n");
    scanf("%d", &n);
    if(n == -1)
    {
        printf("over!\n");
    }
else
    do
    {
        if(n % 2 == 0)
        {
            printf("%d:even\n",n);
            even++;
        }
        else
        {
            printf("%d:odd\n", n);
            odd++;
        }
        scanf("%d", &n);
    }while(n != -1);
    printf("The total number of odd is %d\n", odd);
    printf("The total number of even is %d\n", even);
    return 0;
}
