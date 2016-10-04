#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    int t;
    int i, j;
    int a[10] = {0};
    printf("Please enter the number:\n");
    scanf("%d", &n);
    t = fabs(n);
    for(i = 1; fabs(n) >= pow(10, i); i++)    //i-1 is the number's bits
    {
        for(j = 0; j < 10; j++)
	{
	    if(t%10 == j)
	    {
	        a[j] += 1;
		break;
	    }
	}
	if(t >= 10)
	{    
	    t /= 10;
	}
    } 
    for(j = 0; j < 10; j++)
    {
        if(t%10 == j)
        {
	    a[j] += 1;
            break;
        }
    }
    printf("%d: %d bits\n", n, i);
    for(j = 0; j < 10; j++)
    {
        if(a[j] != 0)
	{
	    printf("%d: %d\n", j, a[j]);
	}
    }
    return 0;
}
