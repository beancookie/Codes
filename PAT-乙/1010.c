#include <stdio.h>

int main()
{
    // freopen("1010.in", "r", stdin);
    int e, c;
    int flag = 1;
    while (scanf("%d%d", &e, &c) != EOF)
    {
        if (e * c != 0)
        {
            if (flag) flag = 0;
            else printf(" ");
            printf("%d %d", e * c, c-1);
        }
    }
    if (flag) printf("0 0");
    return 0;
}