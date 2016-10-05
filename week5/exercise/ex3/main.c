#include <stdio.h>

int main()
{
    int i, j, sum = 0, n;
    scanf("%d", &n);
    for(i = 1, j = n; i < j; i++, j--)
    {
        sum = sum + i + j;
    }
    if(i == j)
    {
        sum += i;
    }
    printf("sum = %d\n", sum);
    return 0;
}


