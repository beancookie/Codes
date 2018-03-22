#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct T
{
    string id;
    float d;
};

bool cmp(const T &a, const T &b)
{
    return a.d < b.d;
}

int main()
{
    // freopen("1082.in", "r", stdin);
    int n;
    cin >> n;
    T a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].id;
        float x, y;
        cin >> x >> y;
        a[i].d = x * x + y * y;
    }
    sort(a, a + n, cmp);
    cout << a[0].id << " " << a[n-1].id;
    return 0;
}