#include <iostream>
using namespace std;

int n;

bool solve(int x)
{
    long r = n * x;
    cout << r << endl;
    while (r)
    {
        if (r % 10 == 0)
            return false;
        r /= 10;
    }
    return true;
}

int main()
{
    freopen("data", "r", stdin);
    cin >> n;
    unsigned int l = 1;
    unsigned int r = 2 << 30;
    int m;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (solve(m))
            l = m;
        else
            r = m + 1;
    }
    cout << m;
    return 0;
}