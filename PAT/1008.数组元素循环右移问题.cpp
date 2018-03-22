#include <iostream>
using namespace std;

void move(int *a, int n)
{
    int t = a[n - 1];
    for (int i = n - 1; i > 0; --i)
        a[i] = a[i - 1];
    a[0] = t;
}

int main()
{
    // freopen("data", "r", stdin);
    int n, k;
    cin >> n >> k;
    int a[n];
    k %= n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < k; ++i)
        move(a, n);
    bool flag = true;
    for (int i = 0; i < n; ++i)
    {
        if (flag)
            flag = false;
        else
            cout << " ";
        cout << a[i];
    }
    return 0;
}