#include <iostream>
#include <string>
using namespace std;

const int MAXN = 10004;

int main()
{
    freopen("in/1017.in", "r", stdin);
    string a;
    int b;
    cin >> a >> b;
    char q[MAXN];
    int r = 0;
    for (int i = 0; i < a.length(); ++i)
    {
        q[i] = (r * 10 + a[i] - '0') / b + '0';
        r = (r * 10 + a[i] - '0') % b;
    }
    if (q[0] == '0' && q[1] != 0)
        cout << q + 1;
    else
        cout << q;
    cout << " " << r;
    return 0;
}