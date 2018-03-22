#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    freopen("1036.in", "r", stdin);
    int n;
    char c;
    cin >> n >> c;
    int l = round(n/2.0);
    for (int i = 0; i < n; ++i)
        cout << c;
    cout << endl;
    for (int i = 0; i < l - 2; ++i)
    {
        cout << c;
        for (int j = 2; j < n; ++j)
            cout << " ";
        cout << c << endl;
    }

    for (int i = 0; i < n; ++i)
        cout << c;
    return 0;
}