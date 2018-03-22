#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    // freopen("1026.in", "r", stdin);
    int c1, c2;
    cin >> c1 >> c2;
    float dur = (c2 - c1) / 100.0;

    int h, m, s;
    h = dur / (60 * 60);
    dur -= h * 60 * 60;
    m = dur / 60;
    dur -= m * 60;
    s = dur;
    printf("%02d:%02d:%02d", h, m, (int)round(dur));
    return 0;
}