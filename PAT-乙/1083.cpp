#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 10005;

int result[MAX_N];

int main()
{
    // freopen("1083.in", "r", stdin);
    memset(result, 0, sizeof result);
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        int ta = i, tb = a[i];
        if (ta <= tb) swap(ta, tb);
        result[ta - tb]++;
    }
    for (int i = MAX_N - 1; i >= 0; --i)
        if (result[i] > 1) cout << i << " " << result[i] << endl;
    return 0;
}