#include <stdio.h>
int main(void)
{
    for (int i = 100; i < 1000; ++i)
    {
        if (i == i * i % 1000)
            printf("%d\n", i);
    }
    return 0;
}