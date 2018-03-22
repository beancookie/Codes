#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int N, D;

struct T
{
    int a, b;
    float c;
};

bool cmp(const T &a, const T &b)
{
    return a.c > b.c;
}

int main()
{
    // freopen("1020.in", "r", stdin);
    cin >> N >> D;
    T a[N];
    for (int i = 0; i < N; ++i)
        cin >> a[i].a;
    for (int i = 0; i < N; ++i)
        cin >> a[i].b;
    for (int i = 0; i < N; ++i)
        a[i].c = a[i].b * 1.0 / a[i].a;
    sort(a, a + N, cmp);
    float total = 0;
    for (int i = 0; i < N; ++i)
    {
        if (D >= a[i].a)
        {
            total += a[i].b;
            D -= a[i].a;
        }
        else if (D < a[i].a && D > 0) 
        {
            total += D * a[i].c;
            D = 0;
        }
        else 
            break;
    }
    cout << fixed << setprecision(2) << total;
    return 0;
}