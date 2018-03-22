#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    // freopen("1032.in", "r", stdin);
    int n;
    cin >> n;
    int a[n + 1];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x;
        cin >> y;
        a[x] += y;
    }
    int max = 0;
    for (int i = 0; i < n + 1; ++i)
    {
        if (a[i] > a[max])
            max = i;
    }
    cout << max << " " << a[max];
    return 0;
}