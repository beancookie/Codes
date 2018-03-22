#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // freopen("1030.in", "r", stdin);
    int n, p;
    cin >> n >> p;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int l = 0, r = n-1;
    while (a[r] > a[l] * p)
    {
        l++;
        if (a[r] <= a[l] * p)
            break;
        r--;
        if (a[r] <= a[l] * p)
            break;
    }
    cout << r - l + 1;
    return 0;
}