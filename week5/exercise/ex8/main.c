#include <stdio.h>

int main()
{
    int n, x = 1;
    printf("Input days:\n");
    scanf("%d", &n);
    for(n; n > 1; n--)
    {
        x = (x + 1) * 2;
    }
    printf("x=%d\n", x);
    return 0;
}
