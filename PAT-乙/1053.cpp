#include <iostream>
using namespace std;

int main()
{
    // freopen("1053.in", "r", stdin);
    int n, D;
    float e;
    cin >> n >> e >> D;
    float sumA = 0, sumB = 0;
    for (int i = 0; i < n; ++i)
    {
        int d;
        cin >> d;
        int sumT = 0;
        float t;
        for (int i = 0; i < d; ++i)
        {
            cin >> t;
            if (t < e)
                sumT++;
        }
        if (sumT > d / 2 && d <= D)
            sumA++;
        else if (sumT > d / 2 && d > D)
            sumB++;
    }
    printf("%.1f%% %.1f%%", sumA / n * 100, sumB / n * 100);
    return 0;
}