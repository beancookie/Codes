#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int sum = 0;
    int cnt = 0;
    if (a > b)
    {
        printf("Sum = 0");
    }
    else
    {
        for (int i = a; i <= b; ++i)
        {
            printf("%5d", i);
            cnt++;
            sum += i;
            if (cnt % 5 == 0)
            {
                printf("\n");
                cnt = 0;
            }
        }
        if (cnt == 0)
            printf("Sum = %d", sum);
        else
            printf("\nSum = %d", sum);
    }
    return 0;
}