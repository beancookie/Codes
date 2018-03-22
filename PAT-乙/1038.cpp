#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 100005;

int main()
{
    // freopen("1038.in", "r", stdin);
    int n, g;
    cin >> n;
    int a[MAXN];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; ++i)
    {
        cin >> g;
        a[g]++;
    }
    cin >> n;
    bool flag = true;
    for (int i = 0; i < n; ++i)
    {
        cin >> g;
        if (flag)
            flag = false;
        else 
            cout << " ";
        cout << a[g];
    }
    return 0;
}