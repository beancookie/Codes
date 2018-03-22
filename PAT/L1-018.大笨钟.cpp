#include <iostream>
#include <cstdio>
// using namespace std;

int main()
{
    // freopen("data", "r", stdin);
    int h, m;
    char c;
    scanf("%d%c%d", &h, &c, &m);
    if (h >= 0 && h < 12)
    {
        printf("Only %02d:%02d.  Too early to Dang.", h, m);
        return 0;
    }
    else
    {
        for (int i = 0; i < h-12; ++i)
            printf("Dang");
        if (m > 0)
            printf("Dang");
    }
    return 0;
}