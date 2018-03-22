#include <iostream>
using namespace std;
const int MAXN = 1005;
const int INFINITY = -(1 << 30);
int head[MAXN] = {INFINITY};
int size;

void push(int x)
{
    int i = ++size;
    for (; x < head[i / 2]; i /= 2)
        head[i] = head[i / 2];
    head[i] = x;
}

int main()
{
    // freopen("in/7-5.in", "r", stdin);
    int n, m, x;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        push(x);
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> x;
        bool flag = true;
        for (int i = x; i > 0; i /= 2)
        {
            if (flag) flag = false;
            else cout << " ";
            cout << head[i];
        }
        cout << "\n";
    }
    return 0;
}