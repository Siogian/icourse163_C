#include <stdio.h>

int main()
{
    long profits[] = {0, 100000, 200000, 400000, 600000, 1000000};
    int base[] = {0, 10000, 17500, 27500, 33500, 39500};
    float percent[] = {10, 7.5, 5, 3, 1.5, 1};
    long bonus;
    int level = 0;
    long profit;
    scanf("%ld", &profit);
    for(int i = 1; i < 6; i++)
    {
        if(profit > profits[i])
        {
            level++;
        }
    }
    bonus = base[level] + (profit - profits[level]) * percent[level]/100.0;
    //printf("%ld", (long) (profit - profits[level]) * percent[level]/100.0);
    printf("bonus=%ld\n", bonus);
    return 0;
}
