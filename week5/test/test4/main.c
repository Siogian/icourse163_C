#include <stdio.h>

int main()
{
    int n, i = 0;
    float h = 100;
    float s = 0;
    printf("Input:\n");
    scanf("%d", &n);
    printf("%d times:\n", n);
    s += h;
    h /= 2;
    for(i = 1; i < n; i++)
    {
       s += 2 * h;
       h = h/2;
    }
    printf("%.3f\n", s);
    printf("%.3f\n", h);
    
    return 0;
}
