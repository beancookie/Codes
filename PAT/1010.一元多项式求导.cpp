#include <iostream>
using namespace std;

int main()
{
    freopen("in/1010.in", "r", stdin);
    int e, f;
    bool flag = true;
    while (cin >> e >> f)
    {
        if (f == 0)
            continue;
        if (flag) flag = false;
        else cout << " ";
        cout << e * f << " " << f - 1;
    }
    if (flag)
        cout <<"0 0";
    return 0;
}