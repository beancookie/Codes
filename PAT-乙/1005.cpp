#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
const int MAXN = 105;

int main()
{
    freopen("1005.in", "r", stdin);
    int n;
    cin >> n;
    int a[n];
    int check[MAXN];
    memset(check, 0, sizeof check);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        check[a[i]] = 1;
    }

    for (int i = 1; i <= 100; ++i)
    {
        if (check[i] != 1) continue;
        cout << i << endl;
        int t = i;
        while (t != 1)
        {
            if (t % 2 == 0)
            {
                t /= 2;
                if (t <= 100)
                {
                    cout << "check:" << t << endl;
                    check[t] = 2;
                }
            }
            else 
            {
                t = (3 * t + 1) / 2;
                if (t <= 100)
                {
                    cout << "check:" << t << endl;
                    check[t] = 2;
                }
            }
        }
    }
    bool flag = true;

    for (int i = 100; i >= 1; --i)
    {
        if (check[i] == 1)
        {
            if (flag) flag = false;
            else cout << " ";
            cout << i;
        }

    }
    return 0;
}