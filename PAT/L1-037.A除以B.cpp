#include <iostream>
using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if (b == 0)
    {
        printf("%d/%d=Error", a, b);
    }
    else if (b < 0)
    {
        printf("%d/(%d)=%.2f", a, b, a * 1.0 / b);
    }
    else
    {
        printf("%d/%d=%.2f", a, b, a*1.0/b);
    }

    return 0;
}