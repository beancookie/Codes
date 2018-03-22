#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // freopen("in/7-18.in", "r", stdin);
    int n;
    queue<int> a;
    queue<int> b;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (x % 2) a.push(x);
        else b.push(x);
    }
    bool flag = true;
    while (!a.empty() || !b.empty())
    {
        if (!a.empty())
        {
            if (flag) flag = false;
            else cout << " ";
            cout << a.front();
            a.pop();
        }

        if (!a.empty())
        {
            if (flag) flag = false;
            else cout << " ";
            cout << a.front();
            a.pop();
        }

        if (!b.empty())
        {
            if (flag) flag = false;
            else cout << " ";
            cout << b.front();
            b.pop();
        }
    }
    return 0;
}