#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main()
{
    // freopen("1049.in", "r", stdin);
    int n;
    cin >> n;
    float a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    float sum = 0;
    for (int i = 0; i < n; ++i)
        sum += (n - i) * a[i];

    float t = sum;
    for (int i = 1; i <= n; ++i)
    {
        float x = (n - i + 1) * a[i-1];
        sum += (t - x);
        t -= x;
    }
    printf("%.2f", sum);
    return 0;
}