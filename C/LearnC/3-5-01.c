#include <stdio.h>

int main(void)
{
    // 输出int二进制
    int number = 8;
    unsigned int mask = 1u<<31;
    for (; mask; mask >>= 1) {
        printf("%d", number&mask ? 1 : 0);
    }
    return 0;
}