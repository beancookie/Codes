#include <iostream>
#include <vector>
using namespace std;

void f(int x, int d)
{
    if (x <= 0) return;
    f(x / d, d);
    cout << x % d;
}

int main()
{
    // freopen("in/1022.in", "r", stdin);
    int a, b, c;
    int d;
    cin >> a >> b >> d;
    c = a + b;
    if (c == 0)
    {
        cout << "0";
        return 0;
    }
    vector<int> v;
    while (c)
    {
        v.push_back(c % d);
        c /= d;
    }
    for (auto it = v.rbegin(); it != v.rend(); ++it)
    {
        cout << *it;
    }
    return 0;
}