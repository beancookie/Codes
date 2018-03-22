#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // freopen("data", "r", stdin);
    int n;
    char c;
    double h;
    scanf("%d\n", &n);
    while (n--)
    {
        scanf("%c %lf\n", &c, &h);
        if (c == 'F')
            printf("%.2f\n", h * 1.09);
        else
            printf("%.2f\n", h / 1.09);
    }
    return 0;
}